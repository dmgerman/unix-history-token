begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|"	@(MHWARNING) .\"    Try to keep only one copy of the documentation around .\"    by re-defining macros and so forth. .\" .fc ^ ~ .\"    I pity the fool who tampers with the next line... .ds ZZ -man .de SC					\" Title section .TH \\$1 \\$2 MH [mh.6] .. .de NA					\" Name section .SH NAME .. .de SY					\" Synopsis section .SH SYNOPSIS .in +.5i .ti -.5i .. .de DE					\" Description section .in -.5i .SH DESCRIPTION .. .de Fi					\" Files section .SH FILES .nf .ta \w'@(MHETCPATH)/ExtraBigFileName  'u .. .de Pr					\" Profile section .SH "
name|PROFILE
operator|\
name|COMPONENTS
literal|" .nf .ta 2.4i .ta \w'ExtraBigProfileName  'u .. .de Ps					\" Profile next .br .. .de Sa					\" See Also section .fi .SH "
name|SEE
operator|\
name|ALSO
literal|" .. .de De					\" Defaults section .SH "
name|DEFAULTS
literal|" .nf .. .de Ds					\" Defaults next .br .. .de Co					\" Context section .fi .SH CONTEXT .. .de Hh					\" Hints section .fi .SH "
name|HELPFUL
name|HINTS
literal|" .. .de Hi					\" History section .fi .SH HISTORY .. .de Bu					\" Bugs section .fi .SH BUGS .. .de En .. .de ip .IP "
operator|\
operator|\
name|$1
literal|"
end_expr_stmt

unit|\\$2 ..
end_unit

