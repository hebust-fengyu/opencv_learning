import cv2 as cv
import numpy as np

#像素加减乘除
def test005():
    pass

#图像像素的读写操作
def test004():
    src = cv.imread("./img/self.jpg")
    rows, cols, ch = src.shape
    dst = np.zeros(src.shape, src.dtype)
    for i in range(rows):
        for j in range(cols):
            dst[rows - 1 - i] = src[i]
    
    cv.imshow("src", src)
    cv.imshow("dst", dst)
    cv.waitKey(0)
    cv.destroyAllWindows()


#图像对象的创建与赋值
def test003():
    src = cv.imread("./img/self.jpg")
    dst2 = np.copy(src)

    cv.imshow("dst2", dst2)
    dst2[200:300, 300:400:, ] = 255
    cv.imshow("dst22", dst2)


    dst3 = np.zeros(src.shape, src.dtype)
    cv.imshow("dst3", dst3)
    dst4 = np.zeros([512, 512], np.uint8)
    cv.imshow("dst4", dst4)

    cv.waitKey(0)
    cv.destroyAllWindows()


#图像色彩空间转换
def test002():
    src = cv.imread("./img/self.jpg")
    cv.namedWindow("src", cv.WINDOW_AUTOSIZE)
    cv.imshow("src", src)

    dst = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
    cv.namedWindow("dst", cv.WINDOW_NORMAL)
    cv.imshow("dst", dst)

    cv.waitKey(0)
    cv.destroyAllWindows()



#图像读取与显示
def test001():
    src = cv.imread("E:\\Desktop\\20200117235347.jpg", cv.IMREAD_GRAYSCALE)
    cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
    cv.imshow("input", src)
    cv.waitKey(0)
    cv.destroyAllWindows()



if __name__ == "__main__":
    main()

