begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: ioptohb.h,v 4.300 91/06/09 06:38:04 root Rel41 $ SONY  *  *	@(#)ioptohb.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IOPTOHB__
end_ifndef

begin_define
define|#
directive|define
name|__IOPTOHB__
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_define
define|#
directive|define
name|iop
value|hb
end_define

begin_define
define|#
directive|define
name|im_driver
value|hm_driver
end_define

begin_define
define|#
directive|define
name|im_ctlr
value|hm_ctlr
end_define

begin_define
define|#
directive|define
name|im_alive
value|hm_alive
end_define

begin_define
define|#
directive|define
name|im_addr
value|hm_addr
end_define

begin_define
define|#
directive|define
name|im_intr
value|hm_intr
end_define

begin_define
define|#
directive|define
name|im_scnum
value|hm_scnum
end_define

begin_define
define|#
directive|define
name|im_hd
value|hm_hd
end_define

begin_define
define|#
directive|define
name|im_tab
value|hm_tab
end_define

begin_define
define|#
directive|define
name|ii_driver
value|hi_driver
end_define

begin_define
define|#
directive|define
name|ii_unit
value|hi_unit
end_define

begin_define
define|#
directive|define
name|ii_ctlr
value|hi_ctlr
end_define

begin_define
define|#
directive|define
name|ii_slave
value|hi_slave
end_define

begin_define
define|#
directive|define
name|ii_addr
value|hi_addr
end_define

begin_define
define|#
directive|define
name|ii_intr
value|hi_intr
end_define

begin_define
define|#
directive|define
name|ii_dk
value|hi_dk
end_define

begin_define
define|#
directive|define
name|ii_flags
value|hi_flags
end_define

begin_define
define|#
directive|define
name|ii_alive
value|hi_alive
end_define

begin_define
define|#
directive|define
name|ii_type
value|hi_type
end_define

begin_define
define|#
directive|define
name|ii_forw
value|hi_forw
end_define

begin_define
define|#
directive|define
name|ii_mi
value|hi_mi
end_define

begin_define
define|#
directive|define
name|ii_hd
value|hi_hd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IOPTOHB__ */
end_comment

end_unit

