 # Movie Recommender

Authors
- Steven Nguyen - https://github.com/steven-nguyen22 
- Ishaan Bijor - http://github.com/ishbij 
- Abhinav Ramachandran - https://github.com/arama033  
 
## Project Description
Importance/Interest
- Steven - This project is interesting to me because I am a big fan of movies and I always use platforms like Netflix and Hulu. Designing this project will allow me to understand how these platforms work behind the scenes like when you click on tabs that sort movies into specific categories. This project can also help me personally because after finishing a movie I often find myself searching google for similar movies with the same genre. 
- Ishaan - Making a decision based on narrowing down our options is a very powerful yet simple and frequent action that is relevant far beyond the scope of movies. This project will teach me the fundamentals of how to properly translate this idea into a reliable piece of code that can be applied to almost anything as long as a user decides it. Movies are also a more interesting way to broaden my reach in this subject of trees. 
- Abhinav - This project is facinating because it is the first time I will get to apply all the coding I have learned class after class to build something I can personally use. I have often found myself browsing endlessly to find a movie to watch, and now my own project will use my preferences to select the perfect movie. We also get to see the full process of working with a team to build a project, from planning to testing. 
#### Languages, Tools, Technologies 
- C++ - Main coding language used. 
- Hammer - Main platform used. 
#### Input/Output
 - The inputs for this project will be the any movie, category, or sub-category a user chooses to remove or add. The outputs for this project will be a list of related movies to the movie the user entered which can be sorted by genre, directors, actors, ratings, etc. 
  
#### Design Patterns 
 - Composite design pattern: The composite design pattern will be used to implement an interface that will work with other classes. The main interface will be a movie class that branches out to different sub classes "below" it like genres, ratings, actors, etc. This pattern will allow us to implement the feature of comparing the movies in different ways, as well as each the data in classes on the same level to recommend a movie for the user. The greatest benefit of this design pattern is a simplicity of its organization, and how we will treat each "node" equally to then carry requests down the length of the tree. 
 - Strategy Design Pattern: This pattern will be critical in our runtime operations available to the user. The various algorithms we need to include work well with this pattern because each function can be done in similar ways. For example, the user at runtime can choose to sort suggestions of a movie, the only change being the filter. The strategy design pattern assists with just this; on the same level of our composition tree, the user chooses a 'strategy' to complete our sort algorithm. 
 
 
Reason for Design Pattern/Implementation 
- Composite design pattern: The most important aspect of this project was a reliable and clear way to organize our movies, categories, subcategories, genres, etc. A composite design pattern goes hand in hand with this idea in that we can have separate paths of movies based on their allocated type without them intersecting. From the perspective of our user, they do not care about the composite attribute of each object, but the inheritance hierarchy that we can draw using this design helps us let users compare and choose a specific movie. Additionally, the inheriting of the methods and variables from one movie specification to another mimics the real-life thought processes of how user want to choose their movie, making the composite pattern very convenient.
- Strategy design pattern: With the ability to access movies completed, the strategy design pattern allows users to sort the movies generated from our suggestion algorithm in different ways. This pattern answers our second challenge, which is offering our user a variety of choices through filter of actor, director, or genre. The classes that will be responsible for these recommendation methods will all be similar to each other, requiring only a change in "strategy" which is why we chose this design pattern as well. This design pattern will also be responsible for our sort the resulting movies after their filters by the ratings, release date, and more that we decide. A key part of this approach is to let the user know all their available options in our movie recommender project, something that the strategy design pattern also is built for. 
 
 Problems expected when implementing 
- When implementing our project, the main issue we expect to encounter is properly storing and managing the massive amounts of movies,sorted groups of movies, and individual criteria all under the same data structure. When traversing through our information, we will need to keep the heirarchy of information in the correct order, while making sure we do not miss or double select any individual movie from our data.   
Why design patterns will work
- We will be using a composite data structure, which will allow us to treat both movies and groups of movies alike. We can create part-whole structures, and as a result represent many more movie groups sorted by different categories than if we chose to not use a composite design pattern. It allows us to organize all our data in an easy to traverse manner. This allows us to have many more sets of movies organized by different specifications in the same data. When we are given a user input for their preffered specifications, we will have more accurate matches and more combinations to select from.
 
 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
