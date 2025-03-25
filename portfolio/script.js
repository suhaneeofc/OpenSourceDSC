// Project data management
const projects = [
    {
        title: "E-commerce Platform",
        description: "Full-stack e-commerce solution",
        technologies: ["React", "Node.js", "MongoDB"]
    },
    {
        title: "Weather App",
        description: "Real-time weather tracking application",
        technologies: ["JavaScript", "API Integration"]
    }
];

// Dynamically render project cards
function renderProjects() {
    const projectContainer = document.querySelector('.project-container');
    
    projects.forEach(project => {
        const projectCard = document.createElement('div');
        projectCard.classList.add('project-card');
        
        projectCard.innerHTML = `
            <h3>${project.title}</h3>
            <p>${project.description}</p>
            <div class="technologies">
                ${project.technologies.map(tech => `<span>${tech}</span>`).join('')}
            </div>
        `;
        
        projectContainer.appendChild(projectCard);
    });
}

// Form validation and submission
function setupContactForm() {
    const form = document.getElementById('contact-form');
    
    form.addEventListener('submit', function(event) {
        event.preventDefault();
        
        // Basic form validation
        const name = form.name.value.trim();
        const email = form.email.value.trim();
        const message = form.message.value.trim();
        
        if (!name || !email || !message) {
            alert('Please fill in all fields');
            return;
        }
        
        // Placeholder for form submission logic
        console.log('Form submitted', { name, email, message });
    });
}

// Initialize page
function initPage() {
    renderProjects();
    setupContactForm();
}

document.addEventListener('DOMContentLoaded', initPage);