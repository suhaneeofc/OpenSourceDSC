// Missing 'use strict' directive

// Poorly declared variables using var instead of let/const
var menuButton;
var navMenu;

// Function to toggle mobile menu - but missing implementation
function toggleMenu() {
    // No actual toggle functionality
    console.log("Menu clicked");
}

// Event listener incorrectly implemented
window.onload = function() {
    menuButton = document.getElementById("menu-btn");
    navMenu = document.getElementById("nav");
    
    // Doesn't check if elements exist before adding listeners
    menuButton.addEventListener("click", toggleMenu);
    
    // Missing error handling
    
    // Attempting to add scroll events but incompletely
    window.addEventListener("scroll", function() {
        // Intended to change header on scroll but not implemented
    });
};

// Form validation with bugs
function validateForm() {
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    
    // Incomplete validation logic
    if (name == "") {
        alert("Name must be filled out");
        return false;
    }
    
    // Missing email validation
    
    return true;
}

// Incomplete dark mode functionality
function toggleDarkMode() {
    // Just toggles a class but doesn't save preference
    document.body.classList.toggle("dark-mode");
}

// Missing DOM ready check
const darkModeButton = document.getElementById("dark-mode-toggle");
// Will throw error if element doesn't exist

// Inefficient code for image loading
function loadGalleryImages() {
    for (var i = 1; i <= 10; i++) {
        // Creates elements but doesn't append them anywhere
        var img = document.createElement("img");
        img.src = "images/gallery/image" + i + ".jpg";
    }
}