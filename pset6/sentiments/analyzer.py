import nltk


class Analyzer():
    """Implements sentiment analysis."""
    positiveWords = set()
    negativeWords = set()

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        file = open(positives, "r")
        for line in file:
            if not line.startswith(';'):
                self.positiveWords.add(line.strip(" "))
        file.close()

        file = open(negatives, "r")
        for line in file:
            if not line.startswith(';'):
                self.negativeWords.add(line.strip(" "))
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        words = text.split()
        score = 0
        for word in words:
            if word.lower() in self.negativeWords:
                score -= 1
            elif word.lower() in self.negativeWords:
                score += 1
            continue

        return score
