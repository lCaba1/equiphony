from flask import Flask

def create_app():
     app = Flask(__name__)

     from string_comp import BP
     app.register_blueprint(BP)

     return app

# flask run --debug 
