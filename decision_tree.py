from __future__ import print_function

training_data = [
    ['zolty', 'koszyczki', 'maly', 1],
    ['zielony', 'koszyczki', 'bardzo_maly', 1],
    ['zielony', 'kielich', 'maly', 2],
    ['czerwony', 'kielich', 'sredni', 2],
    ['zolty', 'dzwoneczki', 'sredni', 3],
    ['czerwony', 'dzwoneczki', 'duzy', 3],
    ['zielony', 'kielich', 'duze', 4],
    ['zolty', 'kielich', 'bardzo_duze', 4],
]

header = ["kolor", "kwiat", "lisc", "gatunek"]

def unique_vals(rows, col):
    """Find the unique values for a column in a dataset."""
    return set([row[col] for row in rows])


def class_counts(rows):
    """Counts the number of each type of example in a dataset."""
    counts = {} 
    for row in rows:
        label = row[-1]
        if label not in counts:
            counts[label] = 0
        counts[label] += 1
    return counts


def is_numeric(value):
    """Test if a value is numeric."""
    return isinstance(value, int) or isinstance(value, float)


class Question:
    """A Question is used to partition a dataset.

    This class just records a 'column number' (e.g., 0 for Color) and a
    'column value' (e.g., Green). The 'match' method is used to compare
    the feature value in an example to the feature value stored in the
    question. See the demo below.
    """

    def __init__(self, column, value):
        self.column = column
        self.value = value

    def match(self, example):
        val = example[self.column]
        if is_numeric(val):
            return val >= self.value
        else:
            return val == self.value

    def __repr__(self):
        condition = "=="
        if is_numeric(self.value):
            condition = ">="
        return "Is %s %s %s?" % (
            header[self.column], condition, str(self.value))

def partition(rows, question):
    """Partitions a dataset.

    For each row in the dataset, check if it matches the question. If
    so, add it to 'true rows', otherwise, add it to 'false rows'.
    """
    true_rows, false_rows = [], []
    for row in rows:
        if question.match(row):
            true_rows.append(row)
        else:
            false_rows.append(row)
    return true_rows, false_rows


def gini(rows):
    """Calculate the Gini Impurity for a list of rows.

    There are a few different ways to do this, I thought this one was
    the most concise. See:
    https://en.wikipedia.org/wiki/Decision_tree_learning#Gini_impurity
    """
    counts = class_counts(rows)
    impurity = 1
    for lbl in counts:
        prob_of_lbl = counts[lbl] / float(len(rows))
        impurity -= prob_of_lbl**2
    return impurity


def info_gain(left, right, current_uncertainty):
    """Information Gain.

    The uncertainty of the starting node, minus the weighted impurity of
    two child nodes.
    """
    p = float(len(left)) / (len(left) + len(right))
    return current_uncertainty - p * gini(left) - (1 - p) * gini(right)


def find_best_split(rows):
    """Find the best question to ask by iterating over every feature / value
    and calculating the information gain."""
    best_gain = 0  
    best_question = None
    current_uncertainty = gini(rows)
    n_features = len(rows[0]) - 1  

    for col in range(n_features):  

        values = set([row[col] for row in rows])  
        for val in values:  

            question = Question(col, val)

            true_rows, false_rows = partition(rows, question)

            if len(true_rows) == 0 or len(false_rows) == 0:
                continue

            gain = info_gain(true_rows, false_rows, current_uncertainty)

            # You actually can use '>' instead of '>=' here
            # but I wanted the tree to look a certain way for our
            # toy dataset.
            if gain >= best_gain:
                best_gain, best_question = gain, question

    return best_gain, best_question


class Leaf:
    """A Leaf node classifies data.

    This holds a dictionary of class (e.g., "Apple") -> number of times
    it appears in the rows from the training data that reach this leaf.
    """

    def __init__(self, rows):
        self.predictions = class_counts(rows)

class Decision_Node:
    """A Decision Node asks a question.

    This holds a reference to the question, and to the two child nodes.
    """

    def __init__(self,
                 question,
                 true_branch,
                 false_branch):
        self.question = question
        self.true_branch = true_branch
        self.false_branch = false_branch

def build_tree(rows):
    """Builds the tree.

    Rules of recursion: 1) Believe that it works. 2) Start by checking
    for the base case (no further information gain). 3) Prepare for
    giant stack traces.
    """

    gain, question = find_best_split(rows)

    if gain == 0:
        return Leaf(rows)

    true_rows, false_rows = partition(rows, question)

    true_branch = build_tree(true_rows)

    false_branch = build_tree(false_rows)

    return Decision_Node(question, true_branch, false_branch)


def print_tree(node, spacing=""):
    """World's most elegant tree printing function."""

    if isinstance(node, Leaf):
        print (spacing + "Predict", node.predictions)
        return

    print (spacing + str(node.question))

    print (spacing + '--> True:')
    print_tree(node.true_branch, spacing + "  ")

    print (spacing + '--> False:')
    print_tree(node.false_branch, spacing + "  ")


my_tree = build_tree(training_data)

print_tree(my_tree)

def classify(row, node):
    """See the 'rules of recursion' above."""

    if isinstance(node, Leaf):
        return node.predictions
    if node.question.match(row):
        return classify(row, node.true_branch)
    else:
        return classify(row, node.false_branch)

def print_leaf(counts):
    """A nicer way to print the predictions at a leaf."""
    total = sum(counts.values()) * 1.0
    probs = {}
    for lbl in counts.keys():
        probs[lbl] = str(int(counts[lbl] / total * 100)) + "%"
    return probs

# Evaluate

with open( 'dane.txt', "r" ) as f:
    testing_data = [ line.split() for line in f ]

"print (testing_data)"

file = open("gatunki.txt", "w")
file.write("")
file.close()

for row in testing_data:
    pom = print_leaf(classify(row, my_tree))
    """print (Actual: %s. Predicted: %s %
           (row[-1], print_leaf(classify(row, my_tree))))"""
    f = open("gatunki.txt", "a")
    if print_leaf(classify(row, my_tree)) == {1: '100%'}:
        """print("ada")"""
        f.write("ada\n")
    if print_leaf(classify(row, my_tree)) == {2: '100%'}:
        """print("ola")"""
        f.write("ola\n")
    if print_leaf(classify(row, my_tree)) == {3: '100%'}:
        """print("dominika")"""
        f.write("dominika\n")
    if print_leaf(classify(row, my_tree)) == {4: '100%'}:
        """print("michal")"""
        f.write("\nmichal")
    f.close()



