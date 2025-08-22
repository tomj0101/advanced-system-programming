import os
import re
from PyPDF2 import PdfMerger

# Regex pattern to extract date from filenames (expects format like "2025-8-15")
date_pattern = re.compile(r'(\d{4})-(\d{1,2})-(\d{1,2})')

# Get all PDF files in current directory
pdf_files = [f for f in os.listdir('.') if f.lower().endswith('.pdf')]

# Sort files by date in descending order (newest first)
def extract_date(filename):
    match = date_pattern.search(filename)
    if match:
        year, month, day = map(int, match.groups())
        return (year, month, day)
    return (0, 0, 0)  # fallback if no date found

pdf_files_sorted = sorted(pdf_files, key=extract_date, reverse=True)

# Merge PDFs
merger = PdfMerger()
for pdf in pdf_files_sorted:
    merger.append(pdf)

# Save merged file
output_path = "Tom_award_2022_2025_sorted.pdf"
merger.write(output_path)
merger.close()

print(f"Merged file saved as {output_path}")
