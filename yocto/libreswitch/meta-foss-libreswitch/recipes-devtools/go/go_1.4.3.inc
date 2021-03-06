require go.inc

GO_BOOTSTRAP_TAG="1_4"
GO_BOOTSTRAP_SOURCE="go${GO_BOOTSTRAP_VERSION}.src.tar.gz"
GO_BOOTSTRAP_URI = "${SRC_URI_PREFIX}/${GO_BOOTSTRAP_SOURCE}"

SRC_URI = "${GO_BOOTSTRAP_URI};name=go_${GO_BOOTSTRAP_TAG};subdir=go-${GO_BOOTSTRAP_VERSION}"
SRC_URI[go_1_4.md5sum] = "dfb604511115dd402a77a553a5923a04"
SRC_URI[go_1_4.sha256sum] = "9947fc705b0b841b5938c48b22dc33e9647ec0752bae66e50278df4f23f64959"

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${GO_BOOTSTRAP_VERSION}/go/LICENSE;md5=591778525c869cdde0ab5a1bf283cd81"

SRC_URI += "\
        file://ccache.patch \
        file://support_new_relocations.patch \
        file://0001-cmd-ld-set-alignment-for-the-.rel.plt-section-on-32-.patch \
        "

S = "${WORKDIR}/go-${PV}/go"

do_install() {
  install -d "${D}${libdir}/${PN}-${PV}"
  tar -C "${WORKDIR}/go-${PV}/go/" -cf - bin include lib pkg src test |
  tar -C "${D}${libdir}/${PN}-${PV}" -xpf -
}

## TODO: implement do_clean() and ensure we actually do rebuild super cleanly
