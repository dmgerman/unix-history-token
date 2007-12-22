begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* misc IOCTL's */
end_comment

begin_comment
comment|/* Unix to Jerq I/O control */
end_comment

begin_define
define|#
directive|define
name|IBCS2_JTYPE
value|('j'<<8)
end_define

begin_define
define|#
directive|define
name|IBCS2_JBOOT
value|(IBCS2_JTYPE|1)
end_define

begin_define
define|#
directive|define
name|IBCS2_JTERM
value|(IBCS2_JTYPE|2)
end_define

begin_define
define|#
directive|define
name|IBCS2_JMPX
value|(IBCS2_JTYPE|3)
end_define

begin_define
define|#
directive|define
name|IBCS2_JTIMO
value|(IBCS2_JTYPE|4)
end_define

begin_define
define|#
directive|define
name|IBCS2_JWINSIZE
value|(IBCS2_JTYPE|5)
end_define

begin_define
define|#
directive|define
name|IBCS2_JTIMOM
value|(IBCS2_JTYPE|6)
end_define

begin_define
define|#
directive|define
name|IBCS2_JZOMBOOT
value|(IBCS2_JTYPE|7)
end_define

begin_define
define|#
directive|define
name|IBCS2_JAGENT
value|(IBCS2_JTYPE|9)
end_define

begin_define
define|#
directive|define
name|IBCS2_JTRUN
value|(IBCS2_JTYPE|10)
end_define

begin_comment
comment|/* Defines for keyboard and display ioctl's */
end_comment

begin_define
define|#
directive|define
name|IBCS2_KIOC
value|('K'<<8)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDDISPTYPE
value|(IBCS2_KIOC|1)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDMAPDISP
value|(IBCS2_KIOC|2)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDUNMAPDISP
value|(IBCS2_KIOC|3)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGKBENT
value|(IBCS2_KIOC|4)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSKBENT
value|(IBCS2_KIOC|5)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGKBMODE
value|(IBCS2_KIOC|6)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSKBMODE
value|(IBCS2_KIOC|7)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDMKTONE
value|(IBCS2_KIOC|8)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGETMODE
value|(IBCS2_KIOC|9)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSETMODE
value|(IBCS2_KIOC|10)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDADDIO
value|(IBCS2_KIOC|11)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDDELIO
value|(IBCS2_KIOC|12)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSBORDER
value|(IBCS2_KIOC|13)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDQUEMODE
value|(IBCS2_KIOC|15)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDVDCTYPE
value|(IBCS2_KIOC|16)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGKBSTATE
value|(IBCS2_KIOC|19)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSETRAD
value|(IBCS2_KIOC|20)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDENABIO
value|(IBCS2_KIOC|60)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDDISABIO
value|(IBCS2_KIOC|61)
end_define

begin_define
define|#
directive|define
name|IBCS2_KIOCINFO
value|(IBCS2_KIOC|62)
end_define

begin_define
define|#
directive|define
name|IBCS2_KIOCSOUND
value|(IBCS2_KIOC|63)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGKBTYPE
value|(IBCS2_KIOC|64)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDGETLED
value|(IBCS2_KIOC|65)
end_define

begin_define
define|#
directive|define
name|IBCS2_KDSETLED
value|(IBCS2_KIOC|66)
end_define

begin_comment
comment|/* Defines for Xenix keyboard and display ioctl's */
end_comment

begin_define
define|#
directive|define
name|IBCS2_MIOC
value|('k'<< 8)
end_define

begin_define
define|#
directive|define
name|IBCS2_GETFKEY
value|(IBCS2_MIOC | 0)
end_define

begin_define
define|#
directive|define
name|IBCS2_SETFKEY
value|(IBCS2_MIOC | 1)
end_define

begin_define
define|#
directive|define
name|IBCS2_GIO_SCRNMAP
value|(IBCS2_MIOC | 2)
end_define

begin_define
define|#
directive|define
name|IBCS2_PIO_SCRNMAP
value|(IBCS2_MIOC | 3)
end_define

begin_define
define|#
directive|define
name|IBCS2_GIO_STRMAP_21
value|(IBCS2_MIOC | 4)
end_define

begin_define
define|#
directive|define
name|IBCS2_PIO_STRMAP_21
value|(IBCS2_MIOC | 5)
end_define

begin_define
define|#
directive|define
name|IBCS2_GIO_KEYMAP
value|(IBCS2_MIOC | 6)
end_define

begin_define
define|#
directive|define
name|IBCS2_PIO_KEYMAP
value|(IBCS2_MIOC | 7)
end_define

begin_define
define|#
directive|define
name|IBCS2_GIO_STRMAP
value|(IBCS2_MIOC | 11)
end_define

begin_define
define|#
directive|define
name|IBCS2_PIO_STRMAP
value|(IBCS2_MIOC | 12)
end_define

end_unit

