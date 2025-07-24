from flask import Flask, render_template
app = Flask(__name__)


@app.route("/show/info")
def index():
    return render_template("index.html")


@app.route("/get/news")
def getnews():
    return render_template("getnews.html")


if __name__ == '__main__':
    app.run()
