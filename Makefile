
website: src/genpage.c
	cc src/genpage.c -o genpage
	cc src/genhome.c -o genhome
	mkdir -p  htmlRecipes recipes

clean:
	rm -rf genpage genhome htmlRecipes recipe-website


