begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley Software License Agreement  * specifies the terms and conditions for redistribution.  */
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
name|sccsid
init|=
literal|"@(#)char.c	5.3 (Berkeley) %G%"
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
name|unsigned
name|short
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
name|_DIG
block|,
name|_DIG
block|,
name|_DIG
block|,
name|_DIG
block|,
comment|/*	4		5		6		7	*/
name|_DIG
block|,
name|_DIG
block|,
name|_DIG
block|,
name|_DIG
block|,
comment|/*	8		9		:		;	*/
name|_DIG
block|,
name|_DIG
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
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	D		E		F		G	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	H		I		J		K	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	L		M		N		O	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	P		Q		R		S	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	T		U		V		W	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	X		Y		Z		[	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
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
name|_LET
block|,
comment|/*	`		a		b		c	*/
name|_Q1
operator||
name|_GLOB
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	d		e		f		g	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	h		i		j		k	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	l		m		n		o	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	p		q		r		s	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	t		u		v		w	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
name|_LET
block|,
comment|/*	x		y		z		{	*/
name|_LET
block|,
name|_LET
block|,
name|_LET
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

