begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/Tekparsetable.c,v $  *	$Header: Tekparsetable.c,v 10.101 86/12/01 21:50:13 jg Rel $  */
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
name|rcsid_Tekparsetable_c
init|=
literal|"$Header: Tekparsetable.c,v 10.101 86/12/01 21:50:13 jg Rel $"
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
file|"Tekparse.h"
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
literal|"@(#)Tekparsetable.c\tX10/6.6B\t12/26/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|int
name|Talptable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_SP
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
name|CASE_IGNORE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tbestable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_VT_MODE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_BYP_STATE
block|,
name|CASE_REPORT
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_IGNORE
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_PAGE
block|,
name|CASE_IGNORE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_COPY
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_GIN
block|,
name|CASE_IGNORE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_SPT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	$		%&		'	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	(		)		*		+	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	,		-		.		/	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	0		1		2		3	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*<		=>		?	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	d		e		f		g	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	h		i		j		k	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	l		m		n		o	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	p		q		r		s	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	t		u		v		w	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	x		y		z		{	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_BYP_STATE
block|,
name|CASE_BYP_STATE
block|,
name|CASE_IGNORE
block|,
name|CASE_BYP_STATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tbyptable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_BES_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
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
name|Tesctable
index|[]
init|=
block|{
comment|/*	NUL		SOH		STX		ETX	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_VT_MODE
block|,
comment|/*	EOT		ENQ		ACK		BEL	*/
name|CASE_CURSTATE
block|,
name|CASE_REPORT
block|,
name|CASE_CURSTATE
block|,
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_IGNORE
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_PAGE
block|,
name|CASE_IGNORE
block|,
name|CASE_APL
block|,
name|CASE_ASCII
block|,
comment|/*	DLE		DC1		DC2		DC3	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	DC4		NAK		SYN		ETB	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_COPY
block|,
comment|/*	CAN		EM		SUB		ESC	*/
name|CASE_BYP_STATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_GIN
block|,
name|CASE_IGNORE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_SPT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	$		%&		'	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	(		)		*		+	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	,		-		.		/	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	0		1		2		3	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	4		5		6		7	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	8		9		:		;	*/
name|CASE_CHAR_SIZE
block|,
name|CASE_CHAR_SIZE
block|,
name|CASE_CHAR_SIZE
block|,
name|CASE_CHAR_SIZE
block|,
comment|/*<		=>		?	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	@		A		B		C	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	D		E		F		G	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	H		I		J		K	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	L		M		N		O	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	P		Q		R		S	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	T		U		V		W	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	\		]		^		_	*/
name|CASE_CURSTATE
block|,
name|CASE_OSC
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	`		a		b		c	*/
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	d		e		f		g	*/
name|CASE_BEAM_VEC
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	h		i		j		k	*/
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	l		m		n		o	*/
name|CASE_BEAM_VEC
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	p		q		r		s	*/
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	t		u		v		w	*/
name|CASE_BEAM_VEC
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_BEAM_VEC
block|,
comment|/*	x		y		z		{	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_CURSTATE
block|,
name|CASE_CURSTATE
block|,
name|CASE_IGNORE
block|,
name|CASE_CURSTATE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tipltable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_PENUP
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
name|CASE_IPL_POINT
block|,
name|CASE_IPL_POINT
block|,
name|CASE_IGNORE
block|,
comment|/*	D		E		F		G	*/
name|CASE_IPL_POINT
block|,
name|CASE_IPL_POINT
block|,
name|CASE_IPL_POINT
block|,
name|CASE_IGNORE
block|,
comment|/*	H		I		J		K	*/
name|CASE_IPL_POINT
block|,
name|CASE_IPL_POINT
block|,
name|CASE_IPL_POINT
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
name|CASE_PENDOWN
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
name|Tplttable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	$		%&		'	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	(		)		*		+	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	,		-		.		/	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	0		1		2		3	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	4		5		6		7	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	8		9		:		;	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*<		=>		?	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	@		A		B		C	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	D		E		F		G	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	H		I		J		K	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	L		M		N		O	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	P		Q		R		S	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	T		U		V		W	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	\		]		^		_	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	`		a		b		c	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	d		e		f		g	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	h		i		j		k	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	l		m		n		o	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	p		q		r		s	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	t		u		v		w	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	x		y		z		{	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|,
name|CASE_PLT_VEC
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tpttable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	$		%&		'	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	(		)		*		+	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	,		-		.		/	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	0		1		2		3	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	4		5		6		7	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	8		9		:		;	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*<		=>		?	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	@		A		B		C	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	D		E		F		G	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	H		I		J		K	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	L		M		N		O	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	P		Q		R		S	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	T		U		V		W	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	\		]		^		_	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	`		a		b		c	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	d		e		f		g	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	h		i		j		k	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	l		m		n		o	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	p		q		r		s	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	t		u		v		w	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	x		y		z		{	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|,
name|CASE_PT_POINT
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tspttable
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
name|CASE_BEL
block|,
comment|/*	BS		HT		NL		VT	*/
name|CASE_BS
block|,
name|CASE_TAB
block|,
name|CASE_LF
block|,
name|CASE_UP
block|,
comment|/*	NP		CR		SO		SI	*/
name|CASE_IGNORE
block|,
name|CASE_CR
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
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_IGNORE
block|,
name|CASE_ESC_STATE
block|,
comment|/*	FS		GS		RS		US	*/
name|CASE_PT_STATE
block|,
name|CASE_PLT_STATE
block|,
name|CASE_IPL_STATE
block|,
name|CASE_ALP_STATE
block|,
comment|/*	SP		!		"		#	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	$		%&		'	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	(		)		*		+	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	,		-		.		/	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	0		1		2		3	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	4		5		6		7	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	8		9		:		;	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*<		=>		?	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	@		A		B		C	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	D		E		F		G	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	H		I		J		K	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	L		M		N		O	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	P		Q		R		S	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	T		U		V		W	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	X		Y		Z		[	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	\		]		^		_	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	`		a		b		c	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	d		e		f		g	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	h		i		j		k	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	l		m		n		o	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	p		q		r		s	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	t		u		v		w	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	x		y		z		{	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
comment|/*	|		}		~		DEL	*/
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|,
name|CASE_SPT_POINT
block|, }
decl_stmt|;
end_decl_stmt

end_unit

