begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|Descr
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Efp
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Gfp
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Indir
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Pfp
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Symbol
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Word1
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|Word2
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_macro
name|PDEF
argument_list|(
argument|abs
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|acos
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|any
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|asin
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|atan
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|atan2
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|bal
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|center
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|close
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|AZ
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|collect
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|AZ
end_endif

begin_macro
name|PDEF
argument_list|(
argument|copy
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|cos
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|cset
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|delete
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_macro
name|PDEF
argument_list|(
argument|display
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|dtor
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|exit
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|exp
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|find
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|get
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|getenv
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|image
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|insert
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_macro
name|PDEF
argument_list|(
argument|integer
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|keyin
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_macro
name|PDEF
argument_list|(
argument|left
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|list
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|log
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|log10
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|many
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|map
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|match
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|member
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_macro
name|PDEF
argument_list|(
argument|move
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|numeric
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|open
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|pop
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|pos
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|EXT
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|proc
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|EXT
end_endif

begin_macro
name|PDEF
argument_list|(
argument|pull
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|push
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|put
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|read
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|reads
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|real
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|repl
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|restty
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_macro
name|PDEF
argument_list|(
argument|reverse
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|right
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|rtod
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|seek
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|EXT
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|seq
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|EXT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|set
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_macro
name|PDEF
argument_list|(
argument|sin
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|sort
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|sqrt
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|stop
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|string
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_macro
name|PDEF
argument_list|(
argument|stty
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_macro
name|PDEF
argument_list|(
argument|system
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|tab
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|table
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|tan
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|trim
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|type
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|upto
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|write
argument_list|)
end_macro

begin_macro
name|PDEF
argument_list|(
argument|writes
argument_list|)
end_macro

end_unit

