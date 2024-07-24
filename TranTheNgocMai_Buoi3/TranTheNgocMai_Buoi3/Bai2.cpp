#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranVuong(int a[MAX][MAX], int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (k + 1);
		}
	}
}

void xuatMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
	printf("Cac phan tu tren duong cheo chinh: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

void xuatDuongCheoPhu(int a[MAX][MAX], int n) {
	printf("Cac phan tu tren duong cheo phu: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][n - 1 - i]);
	}
	printf("\n");
}

void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {
	printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
	for (int k = 1; k < n; k++) {
		printf("Tren: ");
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i][i + k]);
		}
		printf("\nDuoi: ");
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i + k][i]);
		}
		printf("\n");
	}
}

int maxTamGiacTren(int a[MAX][MAX], int n) {
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void sapXepZicZac(int a[MAX][MAX], int n) {
	int temp[MAX * MAX], index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[index++] = a[i][j];
		}
	}
	for (int i = 0; i < index - 1; i++) {
		for (int j = i + 1; j < index; j++) {
			if (temp[i] > temp[j]) {
				int tmp = temp[i];
				temp[i] = temp[j];
				temp[j] = tmp;
			}
		}
	}
	index = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[index++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = temp[index++];
			}
		}
	}
}

void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
	int temp[MAX];
	for (int i = 0; i < n; i++) {
		temp[i] = a[i][i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (temp[i] > temp[j]) {
				int tmp = temp[i];
				temp[i] = temp[j];
				temp[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i][i] = temp[i];
	}
}

int main() {
	srand(time(0));
	int n, k;
	int a[MAX][MAX];
	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Tao ma tran vuong\n");
		printf("2. Xuat ma tran\n");
		printf("3. Xuat cac phan tu tren duong cheo chinh\n");
		printf("4. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
		printf("5. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
		printf("6. Sap xep ma tran tang dan theo kieu zic-zac\n");
		printf("7. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap cap cua ma tran vuong n (n >= 5): ");
			scanf("%d", &n);
			printf("Nhap gia tri toi da k: ");
			scanf("%d", &k);
			taoMaTranVuong(a, n, k);
			break;
		case 2:
			printf("Ma tran vuong:\n");
			xuatMaTran(a, n);
			break;
		case 3:
			xuatDuongCheoChinh(a, n);
			break;
		case 4:
			xuatDuongCheoSongSong(a, n);
			break;
		case 5:
			printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", maxTamGiacTren(a, n));
			break;
		case 6:
			sapXepZicZac(a, n);
			printf("Ma tran sau khi sap xep zic-zac:\n");
			xuatMaTran(a, n);
			break;
		case 7:
			sapXepDuongCheoChinh(a, n);
			printf("Ma tran sau khi sap xep duong cheo chinh tang dan:\n");
			xuatMaTran(a, n);
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
