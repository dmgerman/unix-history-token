begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* defaults for subwindow stuff */
end_comment

begin_define
define|#
directive|define
name|PALBORDER
value|1
end_define

begin_define
define|#
directive|define
name|PALHEIGHT
value|32
end_define

begin_comment
comment|/* operation flags for image display, manipulation operations */
end_comment

begin_define
define|#
directive|define
name|PANEMASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|SELMASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|VOP
value|0x10000
end_define

begin_define
define|#
directive|define
name|VOP_GrayScale
value|0x01
end_define

begin_define
define|#
directive|define
name|VOP_RGB
value|0x02
end_define

begin_define
define|#
directive|define
name|VOP_Normal
value|0x04
end_define

begin_define
define|#
directive|define
name|VOP_Inverse
value|0x08
end_define

begin_define
define|#
directive|define
name|VOP_Initialize
value|0x10
end_define

begin_define
define|#
directive|define
name|COP
value|0x20000
end_define

begin_define
define|#
directive|define
name|COP_Print
value|0x01
end_define

begin_define
define|#
directive|define
name|COP_Pan
value|0x02
end_define

begin_define
define|#
directive|define
name|COP_Zoom2
value|0x04
end_define

begin_define
define|#
directive|define
name|COP_Zoom4
value|0x08
end_define

begin_define
define|#
directive|define
name|COP_Box
value|0x10
end_define

begin_define
define|#
directive|define
name|COP_SetOrigin
value|0x20
end_define

begin_define
define|#
directive|define
name|SOP
value|0x40000
end_define

begin_define
define|#
directive|define
name|SOP_Linear
value|0x01
end_define

begin_define
define|#
directive|define
name|SOP_Log
value|0x02
end_define

begin_define
define|#
directive|define
name|SOP_Sqrt
value|0x04
end_define

begin_define
define|#
directive|define
name|SOP_Histogram
value|0x08
end_define

begin_define
define|#
directive|define
name|FOP
value|0x80000
end_define

begin_define
define|#
directive|define
name|FOP_Read
value|0x01
end_define

begin_define
define|#
directive|define
name|FOP_Flatfield
value|0x02
end_define

begin_define
define|#
directive|define
name|FOP_AddImage
value|0x04
end_define

begin_define
define|#
directive|define
name|FITSBUFLEN
value|2880
end_define

end_unit

