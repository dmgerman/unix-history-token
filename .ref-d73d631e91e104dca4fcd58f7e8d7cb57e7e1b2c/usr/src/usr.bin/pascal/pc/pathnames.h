begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_PATH_PC0
value|"/usr/libexec/pascal/pc0"
end_define

begin_define
define|#
directive|define
name|_PATH_PC1
value|"/usr/libexec/f1"
end_define

begin_define
define|#
directive|define
name|_PATH_PC2
value|"/usr/libexec/pascal/pc2"
end_define

begin_define
define|#
directive|define
name|_PATH_C2
value|"/usr/libexec/c2"
end_define

begin_define
define|#
directive|define
name|_PATH_PC3
value|"/usr/libexec/pascal/pc3"
end_define

begin_define
define|#
directive|define
name|_PATH_PCEXTERN
value|"/usr/lib/pcexterns.o"
end_define

begin_define
define|#
directive|define
name|_PATH_AS
value|"/usr/bin/as"
end_define

begin_define
define|#
directive|define
name|_PATH_LD
value|"/usr/bin/ld"
end_define

begin_define
define|#
directive|define
name|_PATH_CRT0
value|"/usr/lib/crt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_MCRT0
value|"/usr/lib/mcrt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_GCRT0
value|"/usr/lib/gcrt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp"
end_define

begin_define
define|#
directive|define
name|_PATH_CAT
value|"/bin/cat"
end_define

begin_define
define|#
directive|define
name|_PATH_HOWPC
value|"/usr/libdata/pascal/how_pc"
end_define

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|_PATH_DPC0
value|"/usr/src/pgrm/pascal/pc0/obj/pc0"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DPC1
value|"/usr/src/libexec/pcc/f1.vax/obj/f1"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DPC1
value|"/usr/src/libexec/pcc/f1.tahoe/obj/f1"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|NO
name|F1
name|PROGRAM
name|AVAILABLE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_DPC2
value|"/usr/src/pgrm/pascal/pc2/obj/pc2"
end_define

begin_define
define|#
directive|define
name|_PATH_DPC3
value|"/usr/src/pgrm/pascal/pc3/obj/pc3"
end_define

begin_define
define|#
directive|define
name|_PATH_DLPC
value|"/usr/src/lib/libpc/obj/libpc.a"
end_define

end_unit

