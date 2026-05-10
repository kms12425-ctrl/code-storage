FILE = Experimental_Report

XELATEX = C:/Users/Owner/AppData/Local/Programs/MiKTeX/miktex/bin/x64/xelatex.exe -interaction=errorstopmode
BIBTEX = C:/Users/Owner/AppData/Local/Programs/MiKTeX/miktex/bin/x64/bibtex.exe
RM = rm -fr

TEX_SOURCES = $(FILE).tex $(FILE).bib $(FILE).cls $(FILE).cfg $(FILE).bst
LOCAL_IMAGES = $(wildcard images/*)
ASSETS = HUSTBlack.eps HUSTGreen.eps $(LOCAL_IMAGES)

.PHONY: all run clean

all: $(FILE).pdf

run: $(FILE).pdf
	cmd /c start "" $(FILE).pdf

$(FILE).pdf: $(TEX_SOURCES) $(ASSETS)
	$(XELATEX) $(FILE)
	$(BIBTEX) $(FILE)
	$(XELATEX) $(FILE)
	$(XELATEX) $(FILE)

clean:
	$(RM) $(FILE).pdf $(FILE).toc $(FILE).log $(FILE).aux $(FILE).lof $(FILE).lot $(FILE).bbl $(FILE).blg $(FILE).out $(FILE).acn $(FILE).acr $(FILE).alg $(FILE).glg $(FILE).glo $(FILE).gls $(FILE).ist $(FILE).synctex.gz $(FILE).spl
