begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/VTparsetable.c,v $  *	$Header: VTparsetable.c,v 10.101 86/12/01 21:49:52 jg Rel $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_VTparsetable_c
init|=
literal|"$Header: VTparsetable.c,v 10.101 86/12/01 21:49:52 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"VTparse.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccs_id
index|[]
init|=
literal|"@(#)VTparsetable.c\tX10/6.6B\t12/26/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  * Stupid Apollo C preprocessor can't handle long lines.  So... To keep  * it happy, we put each onto a seperate line....  Sigh...  */
end_comment

begin_decl_stmt
name|int
name|groundtable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	$		%&		'	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	(		)		*		+	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	,		-		.		/	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	0		1		2		3	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	4		5		6		7	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	8		9		:		;	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*<		=>		?	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	@		A		B		C	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	D		E		F		G	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	H		I		J		K	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	L		M		N		O	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	P		Q		R		S	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	T		U		V		W	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	\		]		^		_	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	`		a		b		c	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	d		e		f		g	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	h		i		j		k	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	l		m		n		o	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	p		q		r		s	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	t		u		v		w	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	x		y		z		{	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_PRINT
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|csitable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	,		-		.		/	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
comment|/*	4		5		6		7	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
comment|/*	8		9		:		;	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_SEMI
block|,
comment|/*<		=>		?	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_DEC_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_ICH
block|,
name|CASE_CUU
block|,
name|CASE_CUD
block|,
name|CASE_CUF
block|,
comment|/*	D		E		F		G	*/
name|CASE_CUB
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_CUP
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_ED
block|,
name|CASE_EL
block|,
comment|/*	L		M		N		O	*/
name|CASE_IL
block|,
name|CASE_DL
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_DCH
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_DA1
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_CUP
block|,
name|CASE_TBC
block|,
comment|/*	h		i		j		k	*/
name|CASE_SET
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_RST
block|,
name|CASE_SGR
block|,
name|CASE_CPR
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_DECSTBM
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_SUN_EMU
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_DECREQTPARM
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dectable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	,		-		.		/	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
comment|/*	4		5		6		7	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
comment|/*	8		9		:		;	*/
name|CASE_ESC_DIGIT
block|,
name|CASE_ESC_DIGIT
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_SEMI
block|,
comment|/*<		=>		?	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_GROUND_STATE
block|,
name|CASE_ERASE_STATUS
block|,
name|CASE_FROM_STATUS
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_HIDE_STATUS
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_SHOW_STATUS
block|,
comment|/*	T		U		V		W	*/
name|CASE_TO_STATUS
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_DECSET
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_DECRST
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_XTERM_RESTORE
block|,
name|CASE_XTERM_SAVE
block|,
comment|/*	t		u		v		w	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eigtable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	, 	-		.		/	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|esctable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_SCR_STATE
block|,
comment|/*	$		%&		'	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_SCS0_STATE
block|,
name|CASE_SCS1_STATE
block|,
name|CASE_SCS2_STATE
block|,
name|CASE_SCS3_STATE
block|,
comment|/*	,		-		.		/	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_DECSC
block|,
comment|/*	8		9		:		;	*/
name|CASE_DECRC
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_GROUND_STATE
block|,
name|CASE_DECKPAM
block|,
name|CASE_DECKPNM
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_IND
block|,
name|CASE_NEL
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_HTS
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_GROUND_STATE
block|,
name|CASE_RI
block|,
name|CASE_SS2
block|,
name|CASE_SS3
block|,
comment|/*	P		Q		R		S	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_CSI_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_OSC
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_RIS
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_LS2
block|,
name|CASE_LS3
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_LS3R
block|,
name|CASE_LS2R
block|,
name|CASE_LS1R
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iestable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	$		%&		'	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	(		)		*		+	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	,		-		.		/	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	0		1		2		3	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|,
name|CASE_IGNORE_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|igntable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_GROUND_STATE
block|,
name|CASE_IGNORE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_IGNORE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	,		-		.		/	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	4		5		6		7	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	8		9		:		;	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*<		=>		?	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	@		A		B		C	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	D		E		F		G	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	H		I		J		K	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	L		M		N		O	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	T		U		V		W	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	\		]		^		_	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	`		a		b		c	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	d		e		f		g	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	h		i		j		k	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	l		m		n		o	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	p		q		r		s	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	t		u		v		w	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	x		y		z		{	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scrtable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	,		-		.		/	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_GROUND_STATE
block|,
name|CASE_HIDDEN
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_DECALN
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scstable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BELL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_VMOT
block|,
name|CASE_VMOT
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_VMOT
block|,
name|CASE_CR
block|,
name|CASE_SO
block|,
name|CASE_SI
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	$		%&		'	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	(		)		*		+	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	,		-		.		/	*/
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
name|CASE_ESC_IGNORE
block|,
comment|/*	0		1		2		3	*/
name|CASE_GSETS
block|,
name|CASE_GSETS
block|,
name|CASE_GSETS
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GSETS
block|,
name|CASE_GSETS
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|,
name|CASE_GROUND_STATE
block|, }
decl_stmt|;
end_decl_stmt

end_unit

