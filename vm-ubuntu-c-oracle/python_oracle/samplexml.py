import requests
import xmlschema
import xml.etree.ElementTree as ET

# to make it simple use external XML Schema and create a local file from it to validate XML examples

xsd_url = "collection.xsd"

with open("test.xsd", "w", newline="") as out:
    out.write(requests.get(xsd_url).text)
xsd = xmlschema.XMLSchema("test.xsd")

# XML #1 validates to the Schema
url1 = "collection.xml"
xt = ET.fromstring(requests.get(url1).text)
print("xml1 valid=", xsd.is_valid(xt))

xml1 = ET.parse(url1)
print(xml1.getroot())

# XML #2 with invalid structure
url2 = "collection-1_error.xml"
xt = ET.fromstring(requests.get(url2).text)
print("xml2 valid=", xsd.is_valid(xt))

# pre-setup
# pip3 install requests
# pip3 install xmlschema
# python3 samplexml.py
