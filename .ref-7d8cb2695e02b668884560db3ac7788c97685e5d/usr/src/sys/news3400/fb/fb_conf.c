begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: fb_conf.c,v 4.300 91/06/09 06:32:46 root Rel41 $ SONY  *  *	@(#)fb_conf.c	7.3 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"nwb512.h"
end_include

begin_include
include|#
directive|include
file|"nwb514.h"
end_include

begin_include
include|#
directive|include
file|"nwb518.h"
end_include

begin_include
include|#
directive|include
file|"nwb225.h"
end_include

begin_include
include|#
directive|include
file|"nwb251.h"
end_include

begin_include
include|#
directive|include
file|"nwb252.h"
end_include

begin_include
include|#
directive|include
file|"nwb253.h"
end_include

begin_include
include|#
directive|include
file|"nwb254.h"
end_include

begin_include
include|#
directive|include
file|"nwb255.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|news3800
end_ifdef

begin_include
include|#
directive|include
file|"nwb256.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NNWB256
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nwb257.h"
end_include

begin_include
include|#
directive|include
file|"lfbm.h"
end_include

begin_include
include|#
directive|include
file|"pfbc.h"
end_include

begin_include
include|#
directive|include
file|"pfbm.h"
end_include

begin_include
include|#
directive|include
file|"slb101.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_MRX
end_ifdef

begin_include
include|#
directive|include
file|"../../iop/framebuf.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<news3400/iop/framebuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<news3400/fb/fbdefs.h>
end_include

begin_define
define|#
directive|define
name|NFBDEV
define|\
value|NNWB225 + NNWB512 + NNWB518 + NPFBM + NPFBC + NNWB514 + NNWB251 + \ 	NLFBM + NNWB252 + NNWB253 + NNWB254 + NNWB255 + NNWB256 + NNWB257 + \ 	NSLB101
end_define

begin_if
if|#
directive|if
name|NFBDEV
operator|>
literal|0
end_if

begin_decl_stmt
name|struct
name|fbdev
name|fbdev
index|[
name|NFBDEV
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB512
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb512_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb512_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB225
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb225_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb225_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NPFBM
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fbpopm_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbpopm_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB518
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb518_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb518_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NPFBC
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fbpopc_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbpopc_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB514
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb514_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb514_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB251
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb251_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb251_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NLFBM
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fblfbm_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fblfbm_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB252
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb252_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb252_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB253
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb253_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb253_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB254
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb254_probe8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fb254_probe16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb254_setup8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb254_setup16
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB255
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb255_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb255_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB256
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb256_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb256_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NNWB257
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb257_probe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb257_setup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NSLB101
operator|>
literal|0
end_if

begin_function_decl
name|int
name|fb101_probe8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fb101_probe24
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb101_setup8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb101_setup24
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|fbdevsw
name|fbdevsw
index|[]
init|=
block|{
if|#
directive|if
name|NNWB512
operator|>
literal|0
name|NNWB512
block|,
name|fb512_probe
block|,
name|fb512_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB225
operator|>
literal|0
name|NNWB225
block|,
name|fb225_probe
block|,
name|fb225_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NPFBM
operator|>
literal|0
name|NPFBM
block|,
name|fbpopm_probe
block|,
name|fbpopm_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB518
operator|>
literal|0
name|NNWB518
block|,
name|fb518_probe
block|,
name|fb518_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NPFBC
operator|>
literal|0
name|NPFBC
block|,
name|fbpopc_probe
block|,
name|fbpopc_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB514
operator|>
literal|0
name|NNWB514
block|,
name|fb514_probe
block|,
name|fb514_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB251
operator|>
literal|0
name|NNWB251
block|,
name|fb251_probe
block|,
name|fb251_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NLFBM
operator|>
literal|0
name|NLFBM
block|,
name|fblfbm_probe
block|,
name|fblfbm_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB252
operator|>
literal|0
name|NNWB252
block|,
name|fb252_probe
block|,
name|fb252_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB253
operator|>
literal|0
name|NNWB253
block|,
name|fb253_probe
block|,
name|fb253_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB254
operator|>
literal|0
name|NNWB254
block|,
name|fb254_probe16
block|,
name|fb254_setup16
block|,
name|NNWB254
block|,
name|fb254_probe8
block|,
name|fb254_setup8
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB255
operator|>
literal|0
name|NNWB255
block|,
name|fb255_probe
block|,
name|fb255_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB256
operator|>
literal|0
name|NNWB256
block|,
name|fb256_probe
block|,
name|fb256_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NNWB257
operator|>
literal|0
name|NNWB257
block|,
name|fb257_probe
block|,
name|fb257_setup
block|,
endif|#
directive|endif
if|#
directive|if
name|NSLB101
operator|>
literal|0
name|NSLB101
block|,
name|fb101_probe24
block|,
name|fb101_setup24
block|,
name|NSLB101
block|,
name|fb101_probe8
block|,
name|fb101_setup8
block|,
endif|#
directive|endif
literal|0
block|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
operator|(
operator|-
literal|1
operator|)
block|,
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
operator|(
operator|-
literal|1
operator|)
block|, }
decl_stmt|;
end_decl_stmt

end_unit

