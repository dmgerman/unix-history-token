begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: supr.h,v 2.2 84/07/11 15:20:05 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Superstructure for fine focusing.  */
end_comment

begin_comment
comment|/*  * Interpretation of mode and s1, s2, s3:  * WHOLE: whole node is the focus;  * SUBSET: s1/2, s2/2 are first and last child number under focus;  *         even means fixed text, odd means child node;  * SUBRANGE: s1/2 is fixed text number; s2, s3 are 1st&last char;  *         if s1 is odd, ditto for child which must be "text";  * VHOLE: s1/2 is fixed text number; volatile hole before char s2;  *         if s1 is odd, ditto for child which must be "text".  * ATEND: a volatile hole just after the entire node.  * ATBEGIN: ditto just before it.  * SUBLIST: s3 indicates how many times downrite() bring us  *         beyond the focus (i.e., the focus is the subtree below  *         ep->focus EXCLUDING the subtree reached after s3 times  *         downrite().  Note s3> 0.  * FHOLE: Like VHOLE but in Fixed text.  *  * It is assumed that if the focus is a substring of fixed text  * (SUBRANGE, VHOLE), it does not begin or end with lay-out of spaces.  */
end_comment

begin_define
define|#
directive|define
name|WHOLE
value|'W'
end_define

begin_define
define|#
directive|define
name|SUBSET
value|'S'
end_define

begin_define
define|#
directive|define
name|SUBRANGE
value|'R'
end_define

begin_define
define|#
directive|define
name|VHOLE
value|'V'
end_define

begin_define
define|#
directive|define
name|ATEND
value|'E'
end_define

begin_define
define|#
directive|define
name|ATBEGIN
value|'B'
end_define

begin_define
define|#
directive|define
name|SUBLIST
value|'L'
end_define

begin_define
define|#
directive|define
name|FHOLE
value|'F'
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|path
name|focus
decl_stmt|;
name|char
name|mode
decl_stmt|;
name|char
comment|/*bool*/
name|copyflag
decl_stmt|;
name|char
comment|/*bool*/
name|spflag
decl_stmt|;
name|char
comment|/*bool*/
name|changed
decl_stmt|;
name|short
comment|/*0..2*MAXCHILD+1*/
name|s1
decl_stmt|;
name|short
name|s2
decl_stmt|;
name|short
name|s3
decl_stmt|;
name|short
name|highest
decl_stmt|;
name|value
name|copybuffer
decl_stmt|;
comment|/* Actually, a queue */
name|value
name|oldmacro
decl_stmt|;
comment|/* A text */
name|value
name|newmacro
decl_stmt|;
comment|/* A text, too */
name|int
name|generation
decl_stmt|;
block|}
name|environ
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|STRUCTASS
end_ifdef

begin_define
define|#
directive|define
name|Emove
parameter_list|(
name|e1
parameter_list|,
name|e2
parameter_list|)
value|((e2) = (e1))
end_define

begin_else
else|#
directive|else
else|!STRUCTASS
end_else

begin_define
define|#
directive|define
name|Emove
parameter_list|(
name|e1
parameter_list|,
name|e2
parameter_list|)
value|emove(&(e1),&(e2))
end_define

begin_endif
endif|#
directive|endif
endif|!STRUCTASS
end_endif

begin_define
define|#
directive|define
name|Ecopy
parameter_list|(
name|e1
parameter_list|,
name|e2
parameter_list|)
value|ecopy(&(e1),&(e2))
end_define

begin_define
define|#
directive|define
name|Erelease
parameter_list|(
name|e
parameter_list|)
value|erelease(&(e))
end_define

end_unit

