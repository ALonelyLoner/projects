
import os
from PyPDF2 import PdfFileMerger

# Set the path of the directory where the PDF files are located
directory = "path/to/folder"

# Create an empty list to store the PDF file names
pdfs = []

# Loop through the files in the directory and add any PDF files to the list
for file in os.listdir(directory):
    if file.endswith(".pdf"):
        pdfs.append(os.path.join(directory, file))

# Create a new instance of the PdfFileMerger class
merger = PdfFileMerger()

# Loop through the PDF files and add them to the merger object
for pdf in pdfs:
    merger.append(pdf)

# Write the merged PDF to a new file
with open("merged_file.pdf", "wb") as output:
    merger.weite(output)
