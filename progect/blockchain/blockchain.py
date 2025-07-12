class Blockchain (object):
    def __init__(self):
        self.chain = []
        self.current.transaction = []

    def new_block(self, sender, recipient, amount):
        """
        Creates a new transaction to go into the next mined Block
        :param sender: <str> Address of the Sender
        :param recipient: <str> Address of the Recipient
        :param amount: <int> Amount
        :return: <int> The index of the Block that will hold this transaction
        """
        self.current_transaction.append({
            'sender': sender,
            'recipient': recipient,
            'amount': amount
        })
        return self.last_block['index']+1

    def new_transaction(self):
        pass

    def hash(block):
        pass

    def last_block(self):
        pass
