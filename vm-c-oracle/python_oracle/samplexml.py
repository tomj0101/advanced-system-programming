import requests
import xmlschema
import xml.etree.ElementTree as ET

# to make it simple use external XML Schema and create a local file from it to validate XML examples
xsd = xmlschema.XMLSchema("collection.xsd")

# XML #1 validates to the Schema
print("xml1 valid=", xsd.is_valid("collection.xml"))


# XML #2 with invalid structure
print("xml2 valid=", xsd.is_valid("collection-1_error.xml"))

# print xml
col1 = open("collection.xml","r")
print(col1.read())

# pre-setup
# pip3 install requests
# pip3 install xmlschema
# python3 samplexml.py
