def bubbleSort(arr):
    data = [x for x in arr]
    for i in range(1, len(data)):
        if data[i-1] > data[i]:
            temp = data[i-1]
            data[i-1] = data[i]
            data[i] = temp
    print('Pass: ' + str(data))
    for i in range(1, len(data)):
        if data[i-1] > data[i]:
            return bubbleSort(data)
    return data

def selectionSort(arr):
    data = [x for x in arr]
    for i in range(len(data)):
        minimum = data[i]
        index = i
        for j in range(i, len(data)):
            if data[j] < minimum:
                minimum = data[j]
                index = j
        temp = data[i]
        data[i] = data[index]
        data[index] = temp
        print(data)
    return data

def insertionSort(arr):
    data = [x for x in arr]
    for i in range(1, len(data)):
        key = data[i]
        j = i - 1
        while j >= 0 and key < data[j]:
            data[j + 1] = data[j]
            j -= 1
        data[j + 1] = key
        print(data)
    return data


def partition(arr: list, a: int, b: int) -> int:
    i = (a - 1)
    pivot = arr[b]
    for j in range(a, b):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[b] = arr[b], arr[i+1]
    return (i + 1)

def quickSort(arr: list, a: int, b: int):
    if a < b:
        i = partition(arr, a, b)
        quickSort(arr, a, i - 1)
        quickSort(arr, i + 1, b)