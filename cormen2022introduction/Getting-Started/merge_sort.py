
def merge(arr,p,q,r):
    nl = q - p + 1
    nr = r - q

    left = arr[0:q+1]
    right = arr[(q+1):r+1]

    idx = 0
    while left and right:
        if left[0] <= right[0]:
            arr[idx] = left.pop(0)
        else:
            arr[idx] = right.pop(0)
        idx += 1;
    while left:
        arr[idx] = left.pop(0)
        idx += 1
    while right:
        arr[idx] = right.pop(0)
        idx += 1

def main():
    test = [5,6,7,8,9,0,1,2,3,4]
    merge(test, 0, 4, 9)
    print(test)

if __name__ == '__main__':
    main()
