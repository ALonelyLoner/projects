/*
pdfMerger.cpp

"I want to take several pdfs in a folder and concatenate them, how would I do this in c++?"

This file pdfs that are in a common directory and merges them together into a single pdf 
file. The main use case is so that I can take the news and stock pdfs that are avaialbe on
Charles Schwab and make it into a single file. 
Afterwards, I would like to parse theese stock picks and analyze them using some past data. 

@todo Delete the original files.
@todo Make this a function that has inputs instead of variables.
@todo Refactor to simplify (if possible).

Modified:
15 Feb 2023, two, Initial code taken from ChatGPT.
*/

#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    // Set the path of the directory where the PDF files are located
    std::string directory = "/path/to/folder";

    // Create an empty vector to store the PDF file names
    std::vector<std::string> pdfs;

    // Loop through the files in the directory and add any PDF files to the vector
    for (const auto & entry : std::filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".pdf") {
            pdfs.push_back(entry.path());
        }
    }

    // Create a new output PDF document
    auto outputDocument = std::make_shared<Poppler::Document>();

    // Loop through the PDF files and add their pages to the output document
    for (const auto & pdf : pdfs) {
        auto inputDocument = Poppler::Document::load_from_file(pdf);

        for (int i = 0; i < inputDocument->pages(); i++) {
            auto page = inputDocument->create_page(i);
            outputDocument->add_page(page);
        }
    }

    // Save the output document to a file
    outputDocument->write("merged_file.pdf");

    return 0;
}
