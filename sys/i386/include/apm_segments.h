begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * LP (Laptop Package)  *  * Copyright (C) 1994 by HOSOKAWA Tatsumi<hosokawa@mt.cs.keio.ac.jp>  *  * This software may be used, modified, copied, and distributed, in  * both source and binary form provided that the above copyright and  * these terms are retained. Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with its  * use.  *  * Sep., 1994	Implemented on FreeBSD 1.1.5.1R (Toshiba AVS001WD)  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_APM_SEGMENTS_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_APM_SEGMENTS_H
end_define

begin_define
define|#
directive|define
name|SIZEOF_GDT
value|8
end_define

begin_define
define|#
directive|define
name|BOOTSTRAP_GDT_NUM
value|32
end_define

begin_define
define|#
directive|define
name|APM_INIT_CS_INDEX
value|(BOOTSTRAP_GDT_NUM - 4)
end_define

begin_define
define|#
directive|define
name|APM_INIT_DS_INDEX
value|(BOOTSTRAP_GDT_NUM - 3)
end_define

begin_define
define|#
directive|define
name|APM_INIT_CS16_INDEX
value|(BOOTSTRAP_GDT_NUM - 2)
end_define

begin_define
define|#
directive|define
name|APM_INIT_DS16_INDEX
value|(BOOTSTRAP_GDT_NUM - 1)
end_define

begin_define
define|#
directive|define
name|APM_INIT_CS_SEL
value|(APM_INIT_CS_INDEX<< 3)
end_define

begin_define
define|#
directive|define
name|APM_INIT_DS_SEL
value|(APM_INIT_DS_INDEX<< 3)
end_define

begin_define
define|#
directive|define
name|APM_INIT_CS16_SEL
value|(APM_INIT_CS16_INDEX<< 3)
end_define

begin_define
define|#
directive|define
name|APM_INIT_DS16_SEL
value|(APM_INIT_DS16_INDEX<< 3)
end_define

begin_define
define|#
directive|define
name|CS32_ATTRIB
value|0x409e
end_define

begin_define
define|#
directive|define
name|DS32_ATTRIB
value|0x4092
end_define

begin_define
define|#
directive|define
name|CS16_ATTRIB
value|0x009e
end_define

begin_define
define|#
directive|define
name|DS16_ATTRIB
value|0x0092
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

