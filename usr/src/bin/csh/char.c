begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)char.c	4.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sh.char.h"
end_include

begin_decl_stmt
name|char
name|_cmap
index|[
literal|256
index|]
init|=
block|{
comment|/*	nul		soh		stx		etx	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	eot		enq		ack		bel	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	bs		ht		nl		vt	*/
literal|0
block|,
name|_SP
operator||
name|_META
block|,
name|_NL
operator||
name|_META
block|,
literal|0
block|,
comment|/*	np		cr		so		si	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	dle		dc1		dc2		dc3	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	dc4		nak		syn		etb	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	can		em		sub		esc	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	fs		gs		rs		us	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	sp		!		"		#	*/
name|_SP
operator||
name|_META
block|,
literal|0
block|,
name|_Q
block|,
name|_META
block|,
comment|/*	$		%&		'	*/
name|_DOL
block|,
literal|0
block|,
name|_META
block|,
name|_Q
block|,
comment|/*	(		)		*		+	*/
name|_META
block|,
name|_META
block|,
name|_GLOB
block|,
literal|0
block|,
comment|/*	,		-		.		/	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	0		1		2		3	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	4		5		6		7	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	8		9		:		;	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|_META
block|,
comment|/*<		=>		?	*/
name|_META
block|,
literal|0
block|,
name|_META
block|,
name|_GLOB
block|,
comment|/*	@		A		B		C	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	D		E		F		G	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	H		I		J		K	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	L		M		N		O	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	P		Q		R		S	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	T		U		V		W	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	X		Y		Z		[	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|_GLOB
block|,
comment|/*	\		]		^		_	*/
name|_ESC
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	`		a		b		c	*/
name|_Q1
operator||
name|_GLOB
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	d		e		f		g	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	h		i		j		k	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	l		m		n		o	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	p		q		r		s	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	t		u		v		w	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/*	x		y		z		{	*/
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|_GLOB
block|,
comment|/*	|		}		~		del	*/
name|_META
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

