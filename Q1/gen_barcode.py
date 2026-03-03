from itertools import combinations

A, B = map(int, input().split())

barcodes = []
for combo in combinations(range(B), A):
    barcode = ['0'] * B
    for pos in combo:
        barcode[pos] = '1'
    barcodes.append(''.join(barcode))

# Sort by: (rightmost '1' position descending, then reverse lexicographic)
barcodes.sort(key=lambda s: (-s.rfind('1'), s), reverse=True)

for barcode in barcodes:
    print(barcode)