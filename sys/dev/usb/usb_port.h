begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro's to cope with the differences between NetBSD and FreeBSD  */
end_comment

begin_comment
comment|/*  * NetBSD  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_usbverbose.h"
end_include

begin_define
define|#
directive|define
name|DEVICE_NAME
parameter_list|(
name|bdev
parameter_list|)
define|\
value|printf("%s: ", (bdev).dv_xname)
end_define

begin_define
define|#
directive|define
name|DEVICE_MSG
parameter_list|(
name|bdev
end_define

begin_typedef
typedef|typedef
name|struct
name|device
name|bdevice
typedef|;
end_typedef

begin_comment
comment|/* base device */
end_comment

begin_comment
comment|/*  * FreeBSD  *  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"opt_usb.h"
end_include

begin_define
define|#
directive|define
name|DEVICE_NAME
parameter_list|(
name|bdev
parameter_list|)
define|\
value|printf("%s%d: ",	\ 			device_get_name(bdev), device_get_unit(bdev))
end_define

begin_comment
comment|/* XXX Change this when FreeBSD has memset  */
end_comment

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|do{			\ 		if ((v) == 0)		\ 			bzero((d), (s));	\ 		else			\ 			panic("Non zero filler for memset, cannot handle!"); \ 		} while (0)
end_define

begin_comment
comment|/* XXX can't we put this somehow into a typedef? */
end_comment

begin_define
define|#
directive|define
name|bdevice
value|device_t
end_define

begin_comment
comment|/* base device */
end_comment

begin_define
define|#
directive|define
name|USB_MODULE
parameter_list|(
name|name
parameter_list|,
name|driver
parameter_list|,
name|devclass
parameter_list|)
define|\
value|DRIVER_MODULE((name), "usb", (driver), (devclass), usb_driver_load, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * General  *  */
end_comment

begin_define
define|#
directive|define
name|DEVICE_MSG
parameter_list|(
name|bdev
parameter_list|,
name|s
parameter_list|)
value|(DEVICE_NAME(bdev), printf s)
end_define

begin_define
define|#
directive|define
name|DEVICE_ERROR
parameter_list|(
name|bdev
parameter_list|,
name|s
parameter_list|)
value|DEVICE_MSG(bdev, s)
end_define

begin_comment
comment|/* Returns from attach for NetBSD vs. FreeBSD  */
end_comment

begin_comment
comment|/* Error returns */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTACH_ERROR_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|ATTACH_SUCCESS_RETURN
value|return
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTACH_ERROR_RETURN
value|return ENXIO
end_define

begin_define
define|#
directive|define
name|ATTACH_SUCCESS_RETURN
value|return 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The debugging subsystem  */
end_comment

begin_comment
comment|/* XXX to be filled in  */
end_comment

end_unit

