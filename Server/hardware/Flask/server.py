from flask import Flask, request

app = Flask(__name__)

@app.route('/endpoint', methods=['POST'])
def handle_post():
    message = request.form.get('message')
    if message:
        print(f"Received message: {message}")
        return "Message received", 200
    return "No message received", 400

if __name__ == '__main__':
    app.run(host='89.117.21.206', port=5000, debug=True)
    
# Running flask server
# ~/.local/bin/flask run
# or
# python3 server.py
