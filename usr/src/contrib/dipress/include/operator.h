begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Interpress utilities  *  * Copyright (c) 1984, 1985 Xerox Corp.  *  *  Written for Xerox Corporation by William LeFebvre  *  31-May-1984  *  * HISTORY  * 02-Sep-86  Lee Moore (lee) at Xerox Webster Research Center  *	Corrected definition of Get operator.  *  * 03-Jul-86  Lee Moore (lee) at Xerox Webster Research Center  *	Added additional definitons so that users can use identifers  *	with the same case as in "Introduction to Interpress".  *  * 26-apr-85  ed flint (ed) at Xerox Webster Research Center  *	add macros to set standard imager variables  */
end_comment

begin_comment
comment|/*  *  Subroutines to help build interpress files:  *  *  operator interface level - these routines call routines at the literal  *			       interface level to provide an easy way to  *			       write operators along with their parameters.  */
end_comment

begin_comment
comment|/*  *  These routines are all deined with macros that call low level routines  *  found in operator.c.  */
end_comment

begin_define
define|#
directive|define
name|Abs
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_abs, n)
end_define

begin_define
define|#
directive|define
name|Add
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_add, n1, n2)
end_define

begin_define
define|#
directive|define
name|And
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
value|op_ii(OP_and, (long) i1, (long) i2)
end_define

begin_define
define|#
directive|define
name|Ceiling
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_ceiling, n)
end_define

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_copy, (long) i)
end_define

begin_define
define|#
directive|define
name|CorrectSpace
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_correctspace, n1, n2)
end_define

begin_define
define|#
directive|define
name|Div
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_div, n1, n2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|anyop
end_ifdef

begin_define
define|#
directive|define
name|Dup
parameter_list|(
name|a
parameter_list|)
value|op_a(OP_dup, a)
end_define

begin_define
define|#
directive|define
name|Eq
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|op_aa(OP_eq, a1, a2)
end_define

begin_define
define|#
directive|define
name|Exch
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|op_aa(OP_exch, a1, a2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FGet
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_fget, (long) i)
end_define

begin_define
define|#
directive|define
name|Fget
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_fget, (long) i)
end_define

begin_define
define|#
directive|define
name|Floor
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_floor, n)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|anyop
end_ifdef

begin_define
define|#
directive|define
name|FSet
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|op_ai(OP_fset, a, (long) i)
end_define

begin_define
define|#
directive|define
name|Fset
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|op_ai(OP_fset, a, (long) i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Ge
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_ge, n1, n2)
end_define

begin_define
define|#
directive|define
name|Get
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_get, i)
end_define

begin_define
define|#
directive|define
name|Gt
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_gt, n1, n2)
end_define

begin_define
define|#
directive|define
name|IGet
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_iget, (long) i)
end_define

begin_define
define|#
directive|define
name|Iget
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_iget, (long) i)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|anyop
end_ifdef

begin_define
define|#
directive|define
name|ISet
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|op_ai(OP_iset, a, (long) i)
end_define

begin_define
define|#
directive|define
name|Iset
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|op_ai(OP_iset, a, (long) i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LineTo
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_lineto, n1, n2)
end_define

begin_define
define|#
directive|define
name|Lineto
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_lineto, n1, n2)
end_define

begin_define
define|#
directive|define
name|LineToX
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_linetox, n)
end_define

begin_define
define|#
directive|define
name|Linetox
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_linetox, n)
end_define

begin_define
define|#
directive|define
name|LineToY
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_linetoy, n)
end_define

begin_define
define|#
directive|define
name|Linetoy
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_linetoy, n)
end_define

begin_define
define|#
directive|define
name|MakeGray
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_makegray, n)
end_define

begin_define
define|#
directive|define
name|Makegray
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_makegray, n)
end_define

begin_define
define|#
directive|define
name|MakeOutline
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makeoutline, (long) i)
end_define

begin_define
define|#
directive|define
name|Makeoutline
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makeoutline, (long) i)
end_define

begin_define
define|#
directive|define
name|MakeSampledBlack
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makesampledblack, (long) i)
end_define

begin_define
define|#
directive|define
name|Makesampledblack
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makesampledblack, (long) i)
end_define

begin_define
define|#
directive|define
name|MakeVec
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makevec, (long) i)
end_define

begin_define
define|#
directive|define
name|Makevec
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_makevec, (long) i)
end_define

begin_define
define|#
directive|define
name|MakeVecLU
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
value|op_ii(OP_makeveclu, (long) i1, (long) i2)
end_define

begin_define
define|#
directive|define
name|Makeveclu
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
value|op_ii(OP_makeveclu, (long) i1, (long) i2)
end_define

begin_define
define|#
directive|define
name|Mark
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_mark, (long) i)
end_define

begin_define
define|#
directive|define
name|MaskRectangle
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|)
value|op_nnnn(OP_maskrectangle,n1,n2,n3,n4)
end_define

begin_define
define|#
directive|define
name|Maskrectangle
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|)
value|op_nnnn(OP_maskrectangle,n1,n2,n3,n4)
end_define

begin_define
define|#
directive|define
name|MaskTrapezoidX
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|,
name|n5
parameter_list|,
name|n6
parameter_list|)
define|\
value|op_nnnnnn(OP_masktrapezoidx,n1,n2,n3,n4,n5,n6)
end_define

begin_define
define|#
directive|define
name|Masktrapezoidx
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|,
name|n5
parameter_list|,
name|n6
parameter_list|)
define|\
value|op_nnnnnn(OP_masktrapezoidx,n1,n2,n3,n4,n5,n6)
end_define

begin_define
define|#
directive|define
name|MaskTrapezoidY
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|,
name|n5
parameter_list|,
name|n6
parameter_list|)
define|\
value|op_nnnnnn(OP_masktrapezoidy,n1,n2,n3,n4,n5,n6)
end_define

begin_define
define|#
directive|define
name|Masktrapezoidy
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|,
name|n5
parameter_list|,
name|n6
parameter_list|)
define|\
value|op_nnnnnn(OP_masktrapezoidy,n1,n2,n3,n4,n5,n6)
end_define

begin_define
define|#
directive|define
name|MaskUnderline
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_maskunderline, n1, n2)
end_define

begin_define
define|#
directive|define
name|Maskunderline
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_maskunderline, n1, n2)
end_define

begin_define
define|#
directive|define
name|MaskVector
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|)
value|op_nnnn(OP_maskvector,n1,n2,n3,n4)
end_define

begin_define
define|#
directive|define
name|Maskvector
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|,
name|n3
parameter_list|,
name|n4
parameter_list|)
value|op_nnnn(OP_maskvector,n1,n2,n3,n4)
end_define

begin_define
define|#
directive|define
name|Mod
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_mod, n1, n2)
end_define

begin_define
define|#
directive|define
name|MoveTo
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_moveto, n1, n2)
end_define

begin_define
define|#
directive|define
name|Moveto
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_moveto, n1, n2)
end_define

begin_define
define|#
directive|define
name|Mul
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_mul, n1, n2)
end_define

begin_define
define|#
directive|define
name|Neg
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_neg, n)
end_define

begin_define
define|#
directive|define
name|Not
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_not, (long) i)
end_define

begin_define
define|#
directive|define
name|Or
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
value|op_ii(OP_or, (long) i1, (long) i2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|anyop
end_ifdef

begin_define
define|#
directive|define
name|Pop
parameter_list|(
name|a
parameter_list|)
value|op_a(OP_pop, a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Rem
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_rem, n1, n2)
end_define

begin_define
define|#
directive|define
name|Roll
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
value|op_ii(OP_roll, (long) i1, (long) i2)
end_define

begin_define
define|#
directive|define
name|Rotate
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_rotate, n)
end_define

begin_define
define|#
directive|define
name|Round
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_round, n)
end_define

begin_define
define|#
directive|define
name|Scale
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_scale, n)
end_define

begin_define
define|#
directive|define
name|Scale2
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_scale2, n1, n2)
end_define

begin_define
define|#
directive|define
name|SetAmplifySpace
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_amplifySpace)
end_define

begin_define
define|#
directive|define
name|Setamplifyspace
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_amplifySpace)
end_define

begin_define
define|#
directive|define
name|SetCorrectMeasure
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setcorrectmeasure, n1, n2)
end_define

begin_define
define|#
directive|define
name|Setcorrectmeasure
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setcorrectmeasure, n1, n2)
end_define

begin_define
define|#
directive|define
name|SetCorrectPass
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_correctPass)
end_define

begin_define
define|#
directive|define
name|Setcorrectpass
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_correctPass)
end_define

begin_define
define|#
directive|define
name|SetCorrectShrink
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_correctShrink)
end_define

begin_define
define|#
directive|define
name|Setcorrectshrink
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_correctShrink)
end_define

begin_define
define|#
directive|define
name|SetCorrectTolerance
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setcorrecttolerance, n1, n2)
end_define

begin_define
define|#
directive|define
name|Setcorrecttolerance
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setcorrecttolerance, n1, n2)
end_define

begin_define
define|#
directive|define
name|SetFont
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_setfont, (long) i)
end_define

begin_define
define|#
directive|define
name|Setfont
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_setfont, (long) i)
end_define

begin_define
define|#
directive|define
name|SetGray
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setgray, n)
end_define

begin_define
define|#
directive|define
name|Setgray
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setgray, n)
end_define

begin_define
define|#
directive|define
name|SetNoImage
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_noImage)
end_define

begin_define
define|#
directive|define
name|Setnoimage
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_noImage)
end_define

begin_define
define|#
directive|define
name|SetPriorityImportant
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_priorityImportant)
end_define

begin_define
define|#
directive|define
name|Setpriorityimportant
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_priorityImportant)
end_define

begin_define
define|#
directive|define
name|SetStrokeEnd
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_strokeEnd)
end_define

begin_define
define|#
directive|define
name|Setstrokeend
parameter_list|(
name|i
parameter_list|)
value|op_ii(OP_iset, (long) i, (long) I_strokeEnd)
end_define

begin_define
define|#
directive|define
name|SetStrokeWidth
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_strokeWidth)
end_define

begin_define
define|#
directive|define
name|Setstrokewidth
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_strokeWidth)
end_define

begin_define
define|#
directive|define
name|SetUnderlineStart
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_underlineStart)
end_define

begin_define
define|#
directive|define
name|Setunderlinestart
parameter_list|(
name|n
parameter_list|)
value|op_ni(OP_iset, n, (long) I_underlineStart)
end_define

begin_define
define|#
directive|define
name|SetXRel
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setxrel, n)
end_define

begin_define
define|#
directive|define
name|Setxrel
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setxrel, n)
end_define

begin_define
define|#
directive|define
name|SetXY
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setxy, n1, n2)
end_define

begin_define
define|#
directive|define
name|Setxy
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setxy, n1, n2)
end_define

begin_define
define|#
directive|define
name|SetXYRel
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setxyrel, n1, n2)
end_define

begin_define
define|#
directive|define
name|Setxyrel
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_setxyrel, n1, n2)
end_define

begin_define
define|#
directive|define
name|SetYRel
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setyrel, n)
end_define

begin_define
define|#
directive|define
name|Setyrel
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_setyrel, n)
end_define

begin_define
define|#
directive|define
name|Space
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_space, n)
end_define

begin_define
define|#
directive|define
name|Sub
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_sub, n1, n2)
end_define

begin_define
define|#
directive|define
name|Translate
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|op_nn(OP_translate, n1, n2)
end_define

begin_define
define|#
directive|define
name|Trunc
parameter_list|(
name|n
parameter_list|)
value|op_n(OP_trunc, n)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|anyop
end_ifdef

begin_define
define|#
directive|define
name|Type
parameter_list|(
name|a
parameter_list|)
value|op_a(OP_type, a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UnMark
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_unmark, (long) i)
end_define

begin_define
define|#
directive|define
name|Unmark
parameter_list|(
name|i
parameter_list|)
value|op_i(OP_unmark, (long) i)
end_define

end_unit

