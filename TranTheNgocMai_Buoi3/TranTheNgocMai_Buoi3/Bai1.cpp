#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm lấy số ngẫu nhiên từ a đến b
int laySoNgauNhien(int a, int b) {
	return a + rand() % (b - a + 1);
}

// Hàm tạo ma trận ngẫu nhiên với giá trị từ 0 đến k
void taoMaTran(int a[MAX][MAX], int m, int n, int k) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (k + 1);
		}
	}
}

// Hàm tạo ma trận ngẫu nhiên với giá trị từ a đến b
void taoMaTran2(int a[MAX][MAX], int m, int n, int k) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = laySoNgauNhien(0, k);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính tổng giá trị từng dòng
void tongGiaTriTungDong(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int tong = 0;
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		printf("Tong gia tri dong %d: %d\n", i, tong);
	}
}

// Hàm tìm phần tử lớn nhất từng cột
void phanTuLonNhatTungCot(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat cot %d: %d\n", j, max);
	}
}

// Hàm xuất các phần tử thuộc các đường biên
void phanTuDuongBien(int a[MAX][MAX], int m, int n) {
	printf("Cac phan tu thuoc cac duong bien: ");
	for (int j = 0; j < n; j++) {
		printf("%d ", a[0][j]);
	}
	for (int i = 1; i < m - 1; i++) {
		printf("%d %d ", a[i][0], a[i][n - 1]);
	}
	for (int j = 0; j < n; j++) {
		printf("%d ", a[m - 1][j]);
	}
	printf("\n");
}

// Hàm tìm phần tử cực đại
void phanTuCucDai(int a[MAX][MAX], int m, int n) {
	printf("Cac phan tu cuc dai: ");
	for (int i = 1; i < m - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm tìm phần tử hoàng hậu
void phanTuHoangHau(int a[MAX][MAX], int m, int n) {
	printf("Cac phan tu hoang hau: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int max = 1;
			for (int k = 0; k < n; k++) {
				if (a[i][k] > a[i][j]) {
					max = 0;
					break;
				}
			}
			for (int k = 0; k < m; k++) {
				if (a[k][j] > a[i][j]) {
					max = 0;
					break;
				}
			}
			if (max) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm tìm phần tử là điểm yên ngựa
void diemYenNgua(int a[MAX][MAX], int m, int n) {
	printf("Cac phan tu la diem yen ngua: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int min = 1;
			for (int k = 0; k < n; k++) {
				if (a[i][k] < a[i][j]) {
					min = 0;
					break;
				}
			}
			for (int k = 0; k < m; k++) {
				if (a[k][j] > a[i][j]) {
					min = 0;
					break;
				}
			}
			if (min) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm xuất dòng chỉ chứa số chẵn
void xuatDongSoChan(int a[MAX][MAX], int m, int n) {
	int hasEvenRow = 0;
	printf("Cac dong chi chua so chan: \n");

	for (int i = 0; i < m; i++) {
		int isEvenRow = 1;

		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				isEvenRow = 0;
				break;
			}
		}

		if (isEvenRow) {
			hasEvenRow = 1;
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	if (!hasEvenRow) {
		printf("Ma tran khong chua dong chi chua so chan.\n");
	}
}

// Hàm sắp xếp ma trận tăng theo từng dòng
void sapXepMaTran(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

// Hàm main
int main() {
	srand(time(0));
	int m, n, k, a, b;
	int matrix[MAX][MAX];
	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Tao ma tran 0 den k\n");
		printf("2. Tao ma tran a den b\n");
		printf("3. Tinh tong gia tri tung dong\n");
		printf("4. Xuat phan tu lon nhat tren tung cot\n");
		printf("5. Xuat cac phan tu thuoc cac duong bien\n");
		printf("6. Xuat cac phan tu cuc dai\n");
		printf("7. Xuat cac phan tu hoang hau\n");
		printf("8. Xuat cac phan tu la diem yen ngua\n");
		printf("9. Xuat dong chi chua so chan\n");
		printf("10. Sap xep ma tran tang theo tung dong\n");
		printf("11. Xuat ma tran\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap so dong m: ");
			scanf("%d", &m);
			printf("Nhap so cot n: ");
			scanf("%d", &n);
			printf("Nhap gia tri toi da k: ");
			scanf("%d", &k);
			taoMaTran(matrix, m, n, k);
			printf("Ma tran ngau nhien:\n");
			xuatMaTran(matrix, m, n);
			break;
		case 2:
			printf("Nhap so dong m: ");
			scanf("%d", &m);
			printf("Nhap so cot n: ");
			scanf("%d", &n);
			printf("Nhap gia tri a: ");
			scanf("%d", &a);
			printf("Nhap gia tri b: ");
			scanf("%d", &b);
			taoMaTran2(matrix, m, n, b);
			printf("Ma tran ngau nhien:\n");
			xuatMaTran(matrix, m, n);
			break;
		case 3:
			tongGiaTriTungDong(matrix, m, n);
			break;
		case 4:
			phanTuLonNhatTungCot(matrix, m, n);
			break;
		case 5:
			phanTuDuongBien(matrix, m, n);
			break;
		case 6:
			phanTuCucDai(matrix, m, n);
			break;
		case 7:
			phanTuHoangHau(matrix, m, n);
			break;
		case 8:
			diemYenNgua(matrix, m, n);
			break;
		case 9:
			xuatDongSoChan(matrix, m, n);
			break;
		case 10:
			sapXepMaTran(matrix, m, n);
			printf("Ma tran sau khi sap xep:\n");
			xuatMaTran(matrix, m, n);
			break;
		case 11:
			printf("Ma tran hien tai:\n");
			xuatMaTran(matrix, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long thu lai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
