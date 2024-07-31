import requests

SERVER_URL = "https://chat.ifsvivek.tech/ollama/api/generate"  # Define your server URL
API_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6Ijg2YzI2ZDk2LTVlOTMtNDUxYS05ZDdkLTQ0ZDk1ODdmNGYyZSJ9.AkSIm1NsNqTqzUpUaVYL2FF8mfdVrqcWGGl7Zmzm1No"  # Define your API key
MODEL_NAME = "llama3.1:latest"  # Define your model name

def generate_response(prompt):
    url = SERVER_URL
    headers = {"Authorization": f"Bearer {API_KEY}", "Content-Type": "application/json"}
    data = {
        "model": MODEL_NAME,
        "prompt": prompt,
        "stream": False,
    }
    response = requests.post(url, headers=headers, json=data)
    if response.status_code == 200:
        result = response.json()
        if "response" in result:
            print(result["response"])


# Example usage
while True:
    prompt = input("Enter a prompt: ")
    if prompt == "exit":
        break
    generate_response(prompt)
    print()
