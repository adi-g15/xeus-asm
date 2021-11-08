# Maintainer: You Know Me <this_isnt_my_original_work@see.upstream>

pkgname=xeus-asm-git
pkgver=r33.1c82f5a
pkgrel=1
pkgdesc=""
arch=('x86_64')
url="https://github.com/adi-g15/xeus-asm"
license=('Unlicense')
depends=('xeus')
makedepends=('git' 'cmake' 'ninja')
provides=("${pkgname%-git}")
conflicts=("${pkgname%-git}")
source=('git+https://github.com/adi-g15/xeus-asm')
md5sums=('SKIP')

pkgver() {
	cd "$srcdir/${pkgname%-git}"

	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$srcdir/${pkgname%-git}"
	mkdir -p build && cd build
	rm -f CMakeCache.txt
	cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
	cmake --build .
}

package() {
	cd "$srcdir/${pkgname%-git}"
	cd build
	DESTDIR="$pkgdir/" cmake --install .
}
