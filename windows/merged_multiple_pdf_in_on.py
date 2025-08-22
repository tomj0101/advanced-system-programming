from PyPDF2 import PdfMerger

# List of all uploaded PDF files reordered from most recent to oldest
pdf_files_ordered = [
    "Tom EXCELLENCE award 2025-8-15.pdf",
    "Tom TRUST award 2025-8-11.pdf",
    "Tom EXCELLENCE award 2025-5-7.pdf",
    "Tom EXCELLENCE award 2025-2-14.pdf",
    "Tom INNOVATION award 2025-7-1.pdf",
    "Tom SERVICE award 2025-7-1.pdf",
    "Tom EXCELLENCE award 2024-7-19.pdf",
    "Tom EXCELLENCE award 2024-5-17.pdf",
    "Tom EXCELLENCE award 2024-4-13.pdf",
    "Tom EXCELLENCE award 2024-3-19.pdf",
    "Tom EXCELLENCE award 2024-3-1-2.pdf",
    "Tom EXCELLENCE award 2024-3-1-1.pdf",
    "Tom EXCELLENCE award 2024-2-15.pdf",
    "Tom SERVICE award 2023-3-3.pdf",
    "Tom EXCELLENCE award 2022-9-30.pdf",
]

# Create a PDF merger object
merger = PdfMerger()

# Append PDFs in the new order
for pdf in pdf_files_ordered:
    merger.append(pdf)

# Output file path
ordered_output_path = "Tom_award_2022_2025_v2.pdf"

# Write out the merged PDF
merger.write(ordered_output_path)
merger.close()

ordered_output_path
