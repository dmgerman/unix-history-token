begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)open.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* gsi plotting output routines */
end_comment

begin_define
define|#
directive|define
name|DOWN
value|012
end_define

begin_define
define|#
directive|define
name|UP
value|013
end_define

begin_define
define|#
directive|define
name|LEFT
value|010
end_define

begin_define
define|#
directive|define
name|RIGHT
value|040
end_define

begin_define
define|#
directive|define
name|BEL
value|007
end_define

begin_define
define|#
directive|define
name|ACK
value|006
end_define

begin_define
define|#
directive|define
name|PLOTIN
value|063
end_define

begin_define
define|#
directive|define
name|PLOTOUT
value|064
end_define

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_define
define|#
directive|define
name|FF
value|014
end_define

begin_define
define|#
directive|define
name|VERTRESP
value|48
end_define

begin_define
define|#
directive|define
name|HORZRESP
value|60.
end_define

begin_define
define|#
directive|define
name|HORZRES
value|6.
end_define

begin_define
define|#
directive|define
name|VERTRES
value|8.
end_define

begin_comment
comment|/* down is line feed, up is reverse oyne feed,    left is bwckspace, right is space.  48 points per inch    vertically, 60 horizontally */
end_comment

begin_decl_stmt
name|int
name|xnow
decl_stmt|,
name|ynow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OUTF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|ITTY
decl_stmt|,
name|PTTY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|HEIGHT
init|=
literal|6.0
decl_stmt|,
name|WIDTH
init|=
literal|6.0
decl_stmt|,
name|OFFSET
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xscale
decl_stmt|,
name|xoffset
decl_stmt|,
name|yscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|botx
init|=
literal|0.
decl_stmt|,
name|boty
init|=
literal|0.
decl_stmt|,
name|obotx
init|=
literal|0.
decl_stmt|,
name|oboty
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|scalex
init|=
literal|1.
decl_stmt|,
name|scaley
init|=
literal|1.
decl_stmt|;
end_decl_stmt

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|int
name|reset
parameter_list|()
function_decl|;
name|xnow
operator|=
name|ynow
operator|=
literal|0
expr_stmt|;
name|OUTF
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"\r"
argument_list|)
expr_stmt|;
name|gtty
argument_list|(
name|OUTF
argument_list|,
operator|&
name|ITTY
argument_list|)
expr_stmt|;
name|signal
argument_list|(
literal|2
argument_list|,
name|reset
argument_list|)
expr_stmt|;
name|PTTY
operator|=
name|ITTY
expr_stmt|;
name|PTTY
operator|.
name|sg_flags
operator|&=
operator|~
name|CRMOD
expr_stmt|;
comment|/* don't map lf */
name|stty
argument_list|(
name|OUTF
argument_list|,
operator|&
name|PTTY
argument_list|)
expr_stmt|;
comment|/* initialize constants */
name|xscale
operator|=
literal|4096.
operator|/
operator|(
name|HORZRESP
operator|*
name|WIDTH
operator|)
expr_stmt|;
name|yscale
operator|=
literal|4096
operator|/
operator|(
name|VERTRESP
operator|*
name|HEIGHT
operator|)
expr_stmt|;
name|xoffset
operator|=
name|OFFSET
operator|*
name|HORZRESP
expr_stmt|;
return|return;
block|}
end_block

begin_macro
name|openvt
argument_list|()
end_macro

begin_block
block|{
name|openpl
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

