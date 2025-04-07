# cpp
# פרויקט אלגוריתמים על גרפים

בפרויקט הזה מימשתי כמה אלגוריתמים בסיסיים על גרפים לא מכוונים עם משקלים, יחד עם מבני נתונים תומכים.  
הקוד כתוב בשפת ++C בצורה מודולרית, וכל פונקציונליות מחולקת למחלקות שונות.

## 🧱 מבנה הפרויקט

### `Graph`
מייצגת גרף לא מכוון עם משקלים, בעזרת רשימת שכנויות.  
מאפשר:
- להוסיף ולהסיר צלעות
- להדפיס את הגרף
- לגשת לרשימת השכנים של קודקוד מסוים

### `Node`
מבנה שמייצג צומת ברשימת שכנויות.  
כולל:
- `vertex`: הקודקוד השכן
- `weight`: משקל הצלע
- `next`: מצביע לשכן הבא

### `Queue`
מימוש פשוט של תור בעזרת רשימה מקושרת.  
משמש ב־BFS.

### `PriorityQueue`
מימוש של תור עדיפויות מבוסס מערך.  
כולל פעולות:
- `insert`
- `extractMin`
- `decreaseKey`
- `contains`

משמש באלגוריתמים דייקסטרה ופרים.

### `UnionFind`
מימוש של מבנה Union-Find (קבוצות זרות).  
משמש באלגוריתם של קרוסקל כדי למנוע מעגלים.

### `Algorithms`
מחלקה עם פונקציות סטטיות שמממשות את האלגוריתמים הבאים:
- `BFS`
- `DFS`
- `Dijkstra`
- `Prim`
- `Kruskal`

כל פונקציה מחזירה גרף חדש שמייצג את תוצאת האלגוריתם (למשל עץ פורש או עץ סריקה).

---

## 📌 דוגמה

קטע מתוך הקובץ `main.cpp`:

```cpp
Graph g(6);
g.addEdge(0, 1, 7);
g.addEdge(0, 2, 9);
Graph bfsTree = Algorithms::bfs(g, 0);
bfsTree.print_graph();
