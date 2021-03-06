# Default Xilinx BSP Machine settings

# File System Configuration
IMAGE_FSTYPES ?= "cpio tar.gz ext2 ext2.gz.u-boot"
IMAGE_CLASSES += "image_types_uboot"

# Kernel Configuration
PREFERRED_PROVIDER_virtual/kernel ?= "linux-xlnx"
PREFERRED_VERSION_linux-xlnx ?= "3.8%"
PREFERRED_VERSION_linux-yocto ?= "3.10%"

# U-Boot Configuration
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-xlnx"
PREFERRED_PROVIDER_u-boot ?= "u-boot-xlnx"
PREFERRED_VERSION_u-boot-xlnx ?= "v2013.01%"

# Architecture specific kernel configuration parts, defconfigs for Xilinx architectures
MACHINE_KCONFIG_prepend += "common/linux/${SOC_FAMILY}/defconfig_${@'.'.join(d.getVar('LINUX_VERSION', True).split('.')[0:2]).strip('+')}.cfg "

# Common Device Tree Includes
MACHINE_DEVICETREE_append_zynq += " \
		common/zynq7-base.dtsi \
		common/zynq7-mainline-gem.dtsi \
		"
