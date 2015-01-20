DESCRIPTION = "Virtual Tunnels over TCP/IP networks with traffic shaping, compression and encryption."
HOMEPAGE = "http://vtun.sourceforge.net/"
SECTION = "console/network"
LICENSE = "GPLv2"
DEPENDS = "zlib lzo openssl"
LIC_FILES_CHKSUM = "file://vtun.h;startline=1;endline=17;md5=9ac9e7fefca60c72400239e0de40cde8"

SRC_URI = "http://downloads.sourceforge.net/project/vtun/vtun/${PV}/vtun-${PV}.tar.gz"

SRC_URI += "file://remove_strip.patch \
	    file://Add_search_path.patch"

SRC_URI[md5sum] = "f3becf2a0270910a841060c08d1db824"
SRC_URI[sha256sum] = "69dcbe4f8c5ce7d91b4150a6309e536d03b61841169746ca5788413ac7edb9cb"

inherit autotools

do_configure() {
	oe_runconf --with-lzo-headers=${STAGING_INCDIR}/lzo --with-lzo-lib=${STAGING_LIBDIR} --with-ssl-headers=${STAGING_INCDIR}/openssl --with-ssl-lib=${STAGING_LIBDIR}
}
