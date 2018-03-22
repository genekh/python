"""
ExtractDocStrings fills a dictionary with doc strings for each function.
"""

from pythran.passmanager import Transformation

import gast as ast


class ExtractDocStrings(Transformation):
    '''
    Extract Python Doc Strings, removing them from the AST and putting them in
    a dictionary for later use.

    >>> import gast as ast
    >>> from pythran import passmanager, backend
    >>> node = ast.parse("def foo(): 'my doc is cool' ; pass")
    >>> pm = passmanager.PassManager("test")
    >>> _ = pm.apply(ExtractDocStrings, node)
    >>> print pm.dump(backend.Python, node)
    def foo():
        pass
    '''

    def __init__(self):
        super(ExtractDocStrings, self).__init__()
        self.docstrings = dict()

    def run(self, node, ctx):
        super(ExtractDocStrings, self).run(node, ctx)
        return self.docstrings

    def visit_Expr(self, node):
        'Remove other top-level strings'
        if isinstance(node.value, ast.Str):
            return None
        return node

    def visit_documented_node(self, key, node):
        if node.body:
            first_stmt = node.body[0]
            if isinstance(first_stmt, ast.Expr):
                if isinstance(first_stmt.value, ast.Str):
                    self.update = True
                    docstring = first_stmt.value.s
                    self.docstrings[key] = docstring
                    node.body.pop(0)
        return self.generic_visit(node)

    def visit_Module(self, node):
        return self.visit_documented_node(None, node)

    def visit_FunctionDef(self, node):
        return self.visit_documented_node(node.name, node)
