from flask import Blueprint, request
from subprocess import Popen, PIPE


BP = Blueprint("strcomp", "")

@BP.route('/', methods=['GET', 'POST'])
def index():
    out = ""
    text = ""
    if request.method == "POST":
        # прищел POST запрос
        text = request.form['TEXT']

        a = Popen("../build/equiphony2", stdin=PIPE, stdout=PIPE)
        a.stdin.write(text.encode())
        out, err = a.communicate()
        out = out.decode()
    
    '''return f"""
    <html>
    <body>
    <form action=? method=POST>
        <textarea name=TEXT>{text}</textarea>
        <input type="submit">
    </form>
    <h1>Result</h1>
    <pre>
    {out}
    </pre>
    </body>
    </html>"""'''

    return f"""
<html>
<head>
<meta charset="UTF-8">
<title>String Processor</title>
<style>
    body {{
        font-family: Arial, sans-serif;
        background: #f9f9f9;
        padding: 40px;
        max-width: 800px;
        margin: auto;
    }}

    form {{
        margin-bottom: 20px;
    }}

    h2 {{
        font-size: 20px;
        margin-top: 30px;
        margin-bottom: 10px;
        color: #333;
        border-bottom: 1px solid #ccc;
        padding-bottom: 5px;
    }}

    textarea {{
        width: 100%;
        height: 150px;
        font-family: monospace;
        font-size: 14px;
        padding: 10px;
        border: 1px solid #ccc;
        border-radius: 6px;
        resize: vertical;
    }}

    input[type="submit"] {{
        margin-top: 10px;
        padding: 10px 20px;
        background-color: #4CAF50;
        color: white;
        border: none;
        border-radius: 6px;
        cursor: pointer;
    }}

    input[type="submit"]:hover {{
        background-color: #45a049;
    }}

    pre {{
        background: #272822;
        color: #f8f8f2;
        padding: 15px;
        border-radius: 6px;
        overflow-x: auto;
    }}
</style>
</head>
<body>
    <h2>Enter your text:</h2>
    <form action="?" method="POST">
        <textarea name="TEXT" id="text">{text}</textarea><br>
        <input type="submit" value="Submit">
    </form>

    <h2>Result</h2>
    <pre>{out}</pre>
</body>
</html>
"""
