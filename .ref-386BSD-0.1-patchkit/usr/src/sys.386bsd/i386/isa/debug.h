begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* debug.h */
end_comment

begin_define
define|#
directive|define
name|SHOW_A_LOT_NOT
end_define

begin_define
define|#
directive|define
name|BDBTRAP
parameter_list|(
name|name
parameter_list|)
define|\
value|ss ; \ 	cmpb	$0,_bdb_exists ; \ 	je	1f ; \ 	testb	$SEL_RPL_MASK,4(%esp) ; \ 	jne	1f ; \ 	ss ; \ bdb_
comment|/**/
value|name
comment|/**/
value|_ljmp: ; \ 	ljmp	$0,$0 ; \ 1:
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|COUNT_EVENT
parameter_list|(
name|group
parameter_list|,
name|event
parameter_list|)
value|incl	(group) + (event) * 4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COUNT_EVENT
parameter_list|(
name|group
parameter_list|,
name|event
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHOW_A_LOT
end_ifdef

begin_define
define|#
directive|define
name|GREEN
value|0x27
end_define

begin_comment
comment|/* 0x27 for true green, 0x07 for mono */
end_comment

begin_define
define|#
directive|define
name|CLI_STI_X
value|63
end_define

begin_define
define|#
directive|define
name|CPL_X
value|46
end_define

begin_define
define|#
directive|define
name|IMEN_X
value|64
end_define

begin_define
define|#
directive|define
name|IPENDING_X
value|29
end_define

begin_define
define|#
directive|define
name|RED
value|0x47
end_define

begin_comment
comment|/* 0x47 for true red, 0x70 for mono */
end_comment

begin_define
define|#
directive|define
name|SHOW_BIT
parameter_list|(
name|bit
parameter_list|)
value|; \ 	movl	%ecx,%eax ; \ 	shr	$bit,%eax ; \ 	andl	$1,%eax ; \ 	movb	bit_colors(%eax),%al ; \ 	movb	%al,bit * 2 + 1(%ebx)
end_define

begin_define
define|#
directive|define
name|SHOW_BITS
parameter_list|(
name|var
parameter_list|,
name|screen_offset
parameter_list|)
value|; \ 	pushl	%ebx ; \ 	pushl	%ecx ; \ 	movl	_Crtat,%ebx ; \ 	addl	$screen_offset * 2,%ebx ; \ 	movl	_
comment|/**/
value|var,%ecx ; \ 	call	show_bits ; \ 	popl	%ecx ; \ 	popl	%ebx
end_define

begin_define
define|#
directive|define
name|SHOW_CLI
define|\
value|COUNT_EVENT(_intrcnt_show, 0) ; \ 	pushl	%eax ; \ 	movl	_Crtat,%eax ; \ 	movb	$RED,CLI_STI_X * 2 + 1(%eax) ; \ 	popl	%eax
end_define

begin_define
define|#
directive|define
name|SHOW_CPL
define|\
value|COUNT_EVENT(_intrcnt_show, 1) ; \ 	SHOW_BITS(cpl, CPL_X) ; \  #define	SHOW_IMEN \ 	COUNT_EVENT(_intrcnt_show, 2) ; \ 	SHOW_BITS(imen, IMEN_X)
end_define

begin_define
define|#
directive|define
name|SHOW_IPENDING
define|\
value|COUNT_EVENT(_intrcnt_show, 3) ; \ 	SHOW_BITS(ipending, IPENDING_X)
end_define

begin_define
define|#
directive|define
name|SHOW_STI
define|\
value|COUNT_EVENT(_intrcnt_show, 4) ; \ 	pushl	%eax ; \ 	movl	_Crtat,%eax ; \ 	movb	$GREEN,CLI_STI_X * 2 + 1(%eax) ; \ 	popl	%eax
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SHOW_A_LOT */
end_comment

begin_define
define|#
directive|define
name|SHOW_CLI
value|COUNT_EVENT(_intrcnt_show, 0)
end_define

begin_define
define|#
directive|define
name|SHOW_CPL
value|COUNT_EVENT(_intrcnt_show, 1)
end_define

begin_define
define|#
directive|define
name|SHOW_IMEN
value|COUNT_EVENT(_intrcnt_show, 2)
end_define

begin_define
define|#
directive|define
name|SHOW_IPENDING
value|COUNT_EVENT(_intrcnt_show, 3)
end_define

begin_define
define|#
directive|define
name|SHOW_STI
value|COUNT_EVENT(_intrcnt_show, 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHOW_A_LOT */
end_comment

begin_expr_stmt
operator|.
name|data
operator|.
name|globl
name|_bdb_exists
name|_bdb_exists
operator|:
operator|.
name|long
literal|0
operator|.
name|text
end_expr_stmt

end_unit

