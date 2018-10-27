var navbarCollapse = function() {
    if ($("#mainNav").offset().top > 100) {
      $("#mainNav").addClass("navbar-light");
      $("#mainNav").addClass("bg-light");
      $("#mainNav").removeClass("navbar-dark");
    } else {
      $("#mainNav").removeClass("navbar-light");
      $("#mainNav").removeClass("bg-light");
      $("#mainNav").addClass("navbar-dark");
    }
  };
  // Collapse now if page is not at top
  navbarCollapse();
  // Collapse the navbar when page is scrolled
$(window).scroll(navbarCollapse);