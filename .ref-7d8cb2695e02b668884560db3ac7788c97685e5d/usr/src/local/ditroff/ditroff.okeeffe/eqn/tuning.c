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
literal|"@(#)tuning.c	1.1 (CWI) 87/04/01"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  This file contains parameter values for many of the tuning parameters in eqn.  Ideally, these should be settable dynamically, but getting them into a single file is at least a step in the right direction.  Strings are plugged in verbatim. Floats are usually in ems.  */
end_comment

begin_comment
comment|/* In main.c: */
end_comment

begin_decl_stmt
name|float
name|BeforeSub
init|=
literal|1.2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line space before a subscript */
end_comment

begin_decl_stmt
name|float
name|AfterSub
init|=
literal|0.2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line space after a subscript */
end_comment

begin_comment
comment|/* diacrit.c: */
end_comment

begin_decl_stmt
name|float
name|Dvshift
init|=
literal|0.25
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vertical shift for diacriticals on tall letters */
end_comment

begin_decl_stmt
name|float
name|Dhshift
init|=
literal|0.025
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* horizontal shift for tall letters */
end_comment

begin_decl_stmt
name|float
name|Dh2shift
init|=
literal|0.05
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* horizontal shift for small letters */
end_comment

begin_decl_stmt
name|float
name|Dheight
init|=
literal|0.25
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increment to height for diacriticals */
end_comment

begin_decl_stmt
name|float
name|Barv
init|=
literal|0.68
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vertical shift for bar */
end_comment

begin_decl_stmt
name|float
name|Barh
init|=
literal|0.05
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1/2 horizontal shrink for bar */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Vec
init|=
literal|"\\v'-.45m'\\s-1\\(->\\s0\\v'.45m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dyad
init|=
literal|"\\v'-.45m'\\s-1\\z\\(<-\\|\\(->\\s0\\v'.45m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Hat
init|=
literal|"\\v'-.1m'\\s+1^\\s0\\v'.1m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Tilde
init|=
literal|"\\v'-.1m'\\s+1~\\s0\\v'.1m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dot
init|=
literal|"\\v'-.67m'.\\v'.67m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dotdot
init|=
literal|"\\v'-.67m'..\\v'.67m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Utilde
init|=
literal|"\\v'1.0m'\\s+2~\\s-2\\v'-1.0m'"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eqnbox.c: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IRspace
init|=
literal|"\\^"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space between italic& roman boxes */
end_comment

begin_comment
comment|/* fat.c: */
end_comment

begin_decl_stmt
name|float
name|Fatshift
init|=
literal|0.05
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fattening shifts by Fatshift ems */
end_comment

begin_comment
comment|/* funny.c: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Sum
init|=
literal|"\\v'.3m'\\s+5\\(*S\\s-5\\v'-.3m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Union
init|=
literal|"\\v'.3m'\\s+5\\(cu\\s-5\\v'-.3m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Inter
init|=
literal|"\\v'.3m'\\s+5\\(ca\\s-5\\v'-.3m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Prod
init|=
literal|"\\v'.3m'\\s+5\\(*P\\s-5\\v'-.3m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Funnyps
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point size change (== 5 above) */
end_comment

begin_decl_stmt
name|float
name|Funnyht
init|=
literal|0.2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* height correction */
end_comment

begin_decl_stmt
name|float
name|Funnybase
init|=
literal|0.3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base correction */
end_comment

begin_comment
comment|/* integral.c: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Integral
init|=
literal|"\\v'.1m'\\s+4\\(is\\s-4\\v'-.1m'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Intps
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point size change for integral (== 4 above) */
end_comment

begin_decl_stmt
name|float
name|Intht
init|=
literal|1.15
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ht of integral in ems */
end_comment

begin_decl_stmt
name|float
name|Intbase
init|=
literal|0.3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base in ems */
end_comment

begin_decl_stmt
name|float
name|Int1h
init|=
literal|0.4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lower limit left */
end_comment

begin_decl_stmt
name|float
name|Int1v
init|=
literal|0.2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lower limit down */
end_comment

begin_decl_stmt
name|float
name|Int2h
init|=
literal|0.08
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper limit right */
end_comment

begin_decl_stmt
name|float
name|Int2v
init|=
literal|0.1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper limit up */
end_comment

begin_comment
comment|/* matrix.c: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Matspace
init|=
literal|"\\ \\ "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space between matrix columns */
end_comment

begin_comment
comment|/* over.c: */
end_comment

begin_decl_stmt
name|float
name|Overgap
init|=
literal|0.3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* gap between num and denom */
end_comment

begin_decl_stmt
name|float
name|Overwid
init|=
literal|0.5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extra width of box */
end_comment

begin_decl_stmt
name|float
name|Overline
init|=
literal|0.1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extra length of fraction bar */
end_comment

begin_comment
comment|/* paren.c* */
end_comment

begin_decl_stmt
name|float
name|Parenbase
init|=
literal|0.4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shift of base for even count */
end_comment

begin_comment
comment|/* pile.c: */
end_comment

begin_decl_stmt
name|float
name|Pilegap
init|=
literal|0.4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* gap between pile elems */
end_comment

begin_decl_stmt
name|float
name|Pilebase
init|=
literal|0.5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shift base of even # of piled elems */
end_comment

begin_comment
comment|/* shift.c: */
end_comment

begin_decl_stmt
name|float
name|Subbase
init|=
literal|0.2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subscript base belowe main base */
end_comment

begin_decl_stmt
name|float
name|Supshift
init|=
literal|0.4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* superscript .4 up main box */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Sub1space
init|=
literal|"\\|"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* italic sub roman space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Sup1space
init|=
literal|"\\|"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* italic sup roman space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Sub2space
init|=
literal|"\\^"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space after subscripted thing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SS1space
init|=
literal|"\\^"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space before sub in x sub i sup j */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SS2space
init|=
literal|"\\^"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space before sup */
end_comment

begin_comment
comment|/* sqrt.c: */
end_comment

begin_comment
comment|/* sqrt is hard!  punt for now. */
end_comment

begin_comment
comment|/* part of the problem is that every typesetter does it differently */
end_comment

begin_comment
comment|/* and we have several typesetters to run. */
end_comment

begin_comment
comment|/* text.c: */
end_comment

begin_comment
comment|/* ought to be done by a table */
end_comment

end_unit

