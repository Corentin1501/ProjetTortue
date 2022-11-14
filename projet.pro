TEMPLATE = subdirs 
SUBDIRS += expressions
SUBDIRS += tortue.pro

tortue.file = tortue.pro # This specifies the .pro file to use
tortue.depends = expressions/expressions.pro 
