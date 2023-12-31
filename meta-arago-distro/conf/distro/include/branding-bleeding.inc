# Special "bleeding" branding for experimenting and testing unreleased components

require branding-core.inc

# Auto rev important packages to pick up latest
SRCREV_pn-linux-ti-staging = "${AUTOREV}"
SRCREV_pn-linux-ti-staging-rt = "${AUTOREV}"
SRCREV_pn-linux-ti-staging-systest = "${AUTOREV}"
SRCREV_pn-u-boot-ti-staging = "${AUTOREV}"
SRCREV_pn-ltp-ddt = "${AUTOREV}"
#SRCREV_pn-optee-os = "${AUTOREV}"
#SRCREV_pn-optee-client = "${AUTOREV}"
#SRCREV_pn-optee-test = "${AUTOREV}"
SRCREV_pn-arm-trusted-firmware = "${AUTOREV}"

# Point to the latest ti linux firmware
TI_LINUX_FW_SRCREV = "${AUTOREV}"

# Point to the latest ti k3 image gen
K3_IMAGE_GEN_SRCREV = "${AUTOREV}"

# Point to latest nightly metadata
#TI_RTOS_METADATA_URI = "git://git.ti.com/processor-sdk/coresdk_rtos_releases.git"
#TI_RTOS_METADATA_PROTOCOL = "git"
TI_RTOS_METADATA_SRCREV = "${AUTOREV}"
TI_RTOS_METADATA_BRANCH = "next"

# Switch to internal nightlies, force overriding incorrect metadata values
# and ensure parsing won't break w/o metadata file
CORESDK_RTOS_WEBLINK_NIGHTLY ?= "file://empty"
CORESDK_RTOS_WEBLINK_forcevariable = "${CORESDK_RTOS_WEBLINK_NIGHTLY}"
CORESDK_RTOS_FIRMWARE_URL_forcevariable = "${DEFAULT_FIRMWARE_URL}"

# Avoid use of old cached nightly file by using timed prefix
DATEH := "${@time.strftime('%Y%m%d%H',time.gmtime())}"
CORESDK_RTOS_FILE_PREFIX = "${DATEH}-"
CORESDK_RTOS_FILE_SUFFIX = ";downloadfilename=${CORESDK_RTOS_FILE_PREFIX}${DEFAULT_FIRMWARE_FILE}"

# Build and assemble TI-SDK, but don't package it
IMAGE_FSTYPES_pn-tisdk-core-bundle = ""
