from flask import Flask, render_template,request
import sqlite3
import os

#currentdirectory = os.path.dirname(os.path.abspath(__file__))

app = Flask(__name__)

@app.route('/')
def homepage():
    return render_template('home.html')

@app.route('/', methods = ['POST'])
def about():
    name = request.form["Name"]
    phonenumber = request.form["Phonenumber"]
    connection = sqlite3.connect('Phonebook.db')
    cursor = connection.cursor()
    #query = "INSERT INTO Phnbook Values('{n}',{pnm})".format(n = name, pnm = phonenumber)
    query = "SELECT * FROM Phnbook"
    cursor.execute(query)
    connection.commit()
    
@app.route("/resultpage",methods = ["GET"])
def resultpage():
    try:
        if request.method == "GET":
            name = request.args.get("Name")
            connection = sqlite3.connect(currendirectory = 'Phonebook.db')
            cursor = connection.cursor()
            query = "SELECT PhoneNumber from PhnBook WHERE Name = '{n}'".format(n = name)
            result = cursor.execute(query1)
            result = result.fetchall()[0][0]
            return render_template ("resultpage.html",Phonenumber=result)
    except:
        return render_template ("resultpage.html", Phonenumber = "1111")
            



if __name__=="__main__":
    app.run(debug=True)