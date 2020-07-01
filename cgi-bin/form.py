#!/usr/bin/env python3

import cgi
import html

form = cgi.FieldStorage()

form_first_name = form.getfirst('first_name', 'empty')
form_last_name = form.getfirst('last_name', 'empty')
form_country = form.getfirst('country', 'empty')

form_first_name = html.escape(form_first_name)
form_last_name = html.escape(form_last_name)
form_country = html.escape(form_country)

print('Content-type: text/html')
print()
print('''<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Form</title>
    </head>
    <body>''')

print(f'<p>Hello, {form_first_name} {form_last_name} from {form_country}!</p>')
print('<br>')
print('<p><a href="../form.html">Back</a></p>')

print('''</body>
</html>''')
