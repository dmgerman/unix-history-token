begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)piwhoami.h	5.2 (Berkeley) 11/12/86  */
end_comment

begin_comment
comment|/*  *	am i generating an obj file (OBJ),  *	postfix binary input to the 2nd pass of the portable c compiler (PC),  *	or pTrees (PTREE)?  */
end_comment

begin_define
define|#
directive|define
name|OBJ
end_define

begin_undef
undef|#
directive|undef
name|PC
end_undef

begin_undef
undef|#
directive|undef
name|PTREE
end_undef

begin_comment
comment|/*  *	we assume one of the following will be defined by the preprocessor:  *	vax	for vaxes  *	pdp11	for pdp11's  *	mc68000	for motorola mc68000's  *	tahoe	for cci power 6/32's  */
end_comment

begin_comment
comment|/*  *	hardware characteristics:  *	address size (16 or 32 bits) and byte ordering (normal or dec11 family).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_undef
undef|#
directive|undef
name|ADDR16
end_undef

begin_define
define|#
directive|define
name|ADDR32
end_define

begin_define
define|#
directive|define
name|DEC11
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_undef
undef|#
directive|undef
name|ADDR16
end_undef

begin_define
define|#
directive|define
name|ADDR32
end_define

begin_undef
undef|#
directive|undef
name|DEC11
end_undef

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_undef
undef|#
directive|undef
name|ADDR16
end_undef

begin_define
define|#
directive|define
name|ADDR32
end_define

begin_undef
undef|#
directive|undef
name|DEC11
end_undef

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|ADDR16
end_define

begin_undef
undef|#
directive|undef
name|ADDR32
end_undef

begin_define
define|#
directive|define
name|DEC11
end_define

begin_endif
endif|#
directive|endif
endif|pdp11
end_endif

begin_comment
comment|/*  *	am i pi or pxp?  */
end_comment

begin_define
define|#
directive|define
name|PI
end_define

begin_undef
undef|#
directive|undef
name|PXP
end_undef

begin_comment
comment|/*  *	am i both passes, or am i only one of the two passes pi0 or pi1?  */
end_comment

begin_define
define|#
directive|define
name|PI01
end_define

begin_undef
undef|#
directive|undef
name|PI0
end_undef

begin_undef
undef|#
directive|undef
name|PI1
end_undef

begin_define
define|#
directive|define
name|DEBUG
end_define

end_unit

