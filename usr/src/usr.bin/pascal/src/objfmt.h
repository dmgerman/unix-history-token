begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)objfmt.h 1.8 %G%"; */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_comment
comment|/* 	 *	the creation time, the size and the magic number of the obj file 	 */
end_comment

begin_struct
struct|struct
name|pxhdr
block|{
name|long
name|maketime
decl_stmt|;
name|long
name|objsize
decl_stmt|;
name|long
name|symtabsize
decl_stmt|;
name|short
name|magicnum
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HEADER_BYTES
value|1536
end_define

begin_comment
comment|/* the size of px_header */
end_comment

begin_define
define|#
directive|define
name|PX_HEADER
value|"/usr/lib/px_header"
end_define

begin_comment
comment|/* px_header's name */
end_comment

begin_define
define|#
directive|define
name|PI_COMP
value|"/usr/ucb/pi"
end_define

begin_comment
comment|/* the compiler's name */
end_comment

begin_define
define|#
directive|define
name|PX_INTRP
value|"/usr/ucb/px"
end_define

begin_comment
comment|/* the interpreter's name */
end_comment

begin_define
define|#
directive|define
name|PX_DEBUG
value|"/usr/ucb/pdx"
end_define

begin_comment
comment|/* the debugger's name */
end_comment

begin_define
define|#
directive|define
name|INDX
value|1
end_define

begin_comment
comment|/* amt to shift display index */
end_comment

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_comment
comment|/*      *	the file of error messages created by mkstr      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_define
define|#
directive|define
name|ERR_STRNGS
value|"/usr/lib/pi2.0strings"
end_define

begin_define
define|#
directive|define
name|ERR_PATHLEN
value|9
end_define

begin_define
define|#
directive|define
name|HOW_STRNGS
value|"/usr/lib/how_pi\0"
end_define

begin_define
define|#
directive|define
name|HOW_PATHLEN
value|9
end_define

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|ERR_STRNGS
value|"/usr/lib/pc2.0strings"
end_define

begin_define
define|#
directive|define
name|ERR_PATHLEN
value|9
end_define

begin_define
define|#
directive|define
name|HOW_STRNGS
value|"/usr/lib/how_pc\0"
end_define

begin_define
define|#
directive|define
name|HOW_PATHLEN
value|9
end_define

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_comment
comment|/* 	     *	these are because of varying sizes of pointers 	     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|PTR_AS
value|O_AS4
end_define

begin_define
define|#
directive|define
name|PTR_RV
value|O_RV4
end_define

begin_define
define|#
directive|define
name|PTR_IND
value|O_IND4
end_define

begin_define
define|#
directive|define
name|PTR_CON
value|O_CON4
end_define

begin_define
define|#
directive|define
name|PTR_DUP
value|O_SDUP4
end_define

begin_define
define|#
directive|define
name|CON_INT
value|O_CON24
end_define

begin_define
define|#
directive|define
name|INT_TYP
value|(nl + T4INT)
end_define

begin_define
define|#
directive|define
name|PTR_DCL
value|unsigned long
end_define

begin_comment
comment|/* for pointer variables */
end_comment

begin_define
define|#
directive|define
name|SHORTADDR
value|32768
end_define

begin_comment
comment|/* maximum short address */
end_comment

begin_define
define|#
directive|define
name|TOOMUCH
value|65536
end_define

begin_comment
comment|/* maximum variable size */
end_comment

begin_define
define|#
directive|define
name|MAXSET
value|65536
end_define

begin_comment
comment|/* maximum set size */
end_comment

begin_comment
comment|/* 	     * Offsets due to the structure of the runtime stack. 	     * DPOFF1	is the amount of fixed storage in each block allocated 	     * 		as local variables for the runtime system. 	     *		since locals are allocated negative offsets, 	     *		-DPOFF1 is the last used implicit local offset. 	     * DPOFF2	is the size of the block mark. 	     *		since arguments are allocated positive offsets, 	     *		DPOFF2 is the end of the implicit arguments. 	     *		for obj, the first argument has the highest offset 	     *		from the stackpointer.  and the block mark is an 	     *		implicit last parameter. 	     *		for pc, the first argument has the lowest offset 	     *		from the argumentpointer.  and the block mark is an 	     *		implicit first parameter. 	     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_define
define|#
directive|define
name|DPOFF1
value|0
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|32
end_define

begin_define
define|#
directive|define
name|INPUT_OFF
value|-8
end_define

begin_comment
comment|/* offset of `input' */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|-4
end_define

begin_comment
comment|/* offset of `output' */
end_comment

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|DPOFF1
value|( sizeof rtlocs - sizeof rtlocs.unwind )
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|( sizeof (long) )
end_define

begin_define
define|#
directive|define
name|INPUT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|0
end_define

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_define
define|#
directive|define
name|MAGICNUM
value|0403
end_define

begin_comment
comment|/* obj magic number */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|PTR_AS
value|O_AS2
end_define

begin_define
define|#
directive|define
name|PTR_RV
value|O_RV2
end_define

begin_define
define|#
directive|define
name|PTR_IND
value|O_IND2
end_define

begin_define
define|#
directive|define
name|PTR_CON
value|O_CON2
end_define

begin_define
define|#
directive|define
name|PTR_DUP
value|O_SDUP2
end_define

begin_define
define|#
directive|define
name|CON_INT
value|O_CON2
end_define

begin_define
define|#
directive|define
name|INT_TYP
value|(nl + T2INT)
end_define

begin_define
define|#
directive|define
name|PTR_DCL
value|char *
end_define

begin_define
define|#
directive|define
name|TOOMUCH
value|50000
end_define

begin_define
define|#
directive|define
name|SHORTADDR
value|65536
end_define

begin_define
define|#
directive|define
name|MAXSET
value|65536
end_define

begin_comment
comment|/* maximum set size */
end_comment

begin_define
define|#
directive|define
name|DPOFF1
value|0
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|18
end_define

begin_comment
comment|/* sizeof(struct stack) */
end_comment

begin_define
define|#
directive|define
name|INPUT_OFF
value|-2
end_define

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|-4
end_define

begin_define
define|#
directive|define
name|MAGICNUM
value|0404
end_define

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

end_unit

