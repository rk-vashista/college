import random
#chatbot using dictionary
def chatbot():
    """ Simple chatbot that responds to user input """
    responses = {
        "hello": "Hello!",
        "how are you?": "I'm good, thank you!",
        "bye": "Goodbye!",
        "default": "I'm sorry, I don't understand.",
    }
    
    while True:
        user_input = input("You: ").lower()
        response = responses.get(user_input, responses["default"])
        print(f"Bot: {response}")
        
        if user_input == "bye":
            break
chatbot()